module behavioral_cipher(a, b, sum, addsub);
  input [7:0] a;
  input [3:0] b;
  output reg [7:0] sum;
  input addsub;

  always @ (a, b, addsub)
    if (addsub == 1) begin
      sum = a - b;
    end
    else begin
      sum = a + b;
    end
endmodule
