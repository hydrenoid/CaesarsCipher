module behavioral_cipher(
	input [7:0] a, 
	input [3:0] b, 
	input enable,
	
	output trireg [7:0] sum, 
	input addsub);
  
	reg [7:0] sum_reg;
	
	
  always @ (a, b, addsub) begin
    if (addsub == 1) begin
      sum_reg <= a - b;
    end
    else begin
      sum_reg <= a + b;
    end
	end
	
	assign sum = enable ? sum_reg : 8'bzzzzzzzz;
endmodule
