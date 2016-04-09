//module mirror_spi_driver(clk, ss, datain, LEDG);
module mirror_spi_driver(clk, SCK, MOSI, MISO, SSEL, LED);
input clk;

input SCK, SSEL, MOSI;
output MISO;

output LED;


// sync SCK to the FPGA clock using a 3-bits shift register
reg [2:0] SCKr;  always @(posedge clk) SCKr <= {SCKr[1:0], SCK};
wire SCK_risingedge = (SCKr[2:1]==2'b01);  // now we can detect SCK rising edges
wire SCK_fallingedge = (SCKr[2:1]==2'b10);  // and falling edges

// same thing for SSEL
reg [2:0] SSELr;  always @(posedge clk) SSELr <= {SSELr[1:0], SSEL};
wire SSEL_active = ~SSELr[1];  // SSEL is active low
wire SSEL_startmessage = (SSELr[2:1]==2'b10);  // message starts at falling edge
wire SSEL_endmessage = (SSELr[2:1]==2'b01);  // message stops at rising edge

// and for MOSI
reg [1:0] MOSIr;  always @(posedge clk) MOSIr <= {MOSIr[0], MOSI};
wire MOSI_data = MOSIr[1];

// we handle SPI in 8-bits format, so we need a 3 bits counter to count the bits as they come in
reg [2:0] bitcnt;

reg byte_received;  // high when a byte has been received
reg [7:0] byte_data_received;

always @(posedge clk)
begin
  if(~SSEL_active)
    bitcnt <= 3'b000;
  else
  if(SCK_risingedge)
  begin
    bitcnt <= bitcnt + 3'b001;

    // implement a shift-left register (since we receive the data MSB first)
    byte_data_received <= {byte_data_received[6:0], MOSI_data};
  end
end

always @(posedge clk) byte_received <= SSEL_active && SCK_risingedge && (bitcnt==3'b111);

// we use the LSB of the data received to control an LED
reg [3:0]LED = 4'b0000;
always @(posedge clk) 
	if(byte_received) 
		if(byte_data_received == 8'b1100001)
			begin
			LED[0] <= 1;
			end
		else if(byte_data_received == 8'b1100010)
			begin
			LED[1] <= 1;
			end
		else if(byte_data_received == 8'b1100011)
			begin
			LED[2] <= 1;
			end
		else if(byte_data_received == 8'b1100100)
			LED[3] <= 1;
endmodule 
//input clk, ss;
//input datain;
//
////output dataout;
//
//reg frame_buff[39:0][14:0];
//
//integer bit = 0, col = 0, row = 0;
//reg [7:0]byte_builder;
//
//output reg [3:0]LEDG = 4'b0000;
//
////always @(posedge clk)
////begin
////	if(~ss) //are we selected?
////	begin //yes
////		 //we take in a single bit at a time, group together to form byte
////		 //insert byte into corresponding location in frame_buff
////		 
////		//40 char wide loop
////		for (col = 0; col < 40; col = col + 1)
////		begin
////			//15 char deep loop
////			for (row = 0; row < 15; row = row + 1)
////			begin
////			
////				//assign each bit in byte builder to the 
////				//corresponding value of datain
////				byte_builder <= 0;
////				//8 bit loop
////				for (bit = 0; bit < 8; bit = bit + 1)
////				begin
////					byte_builder[bit] = datain; 
////				end
////				
////				frame_buff[col][row] <= byte_builder;
////			end
////		end
////		
////	end
////
////end
//
//always @(posedge clk)
//begin
//if(~ss)
//begin
//	if(bit < 8)
//		begin
//		byte_builder[bit] = datain;
//		bit <= bit + 1;
//		end
//	else
//		begin
//		bit = 0;
//		frame_buff[col][row] <= byte_builder;
//		if(col < 40)
//			col <= col + 1;
//		else
//			begin
//			col <= 0;
//			if(row < 15)
//				row <= row + 1;
//			else
//				row <= 0;
//			end
//		
//		end
//end	
//end
//
//always @*
//begin
//	if(byte_builder == 8'b1100001)
//		begin
//		LEDG[0] <= 1;
//		end
//	else if(byte_builder == 8'b1100010)
//		begin
//		LEDG[1] <= 1;
//		end
//	else if(byte_builder == 8'b1100011)
//		begin
//		LEDG[2] <= 1;
//		end
//	else if(byte_builder == 8'b1100100)
//		LEDG[3] <= 1;
//end 
