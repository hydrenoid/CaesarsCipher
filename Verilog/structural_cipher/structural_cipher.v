module structural_cipher(a, b, d, sum, cout);
  input [7:0] a;
  input [3:0] b;
  input d;
  output [8:0] sum;
  output cout;

  wire [6:0] carry;

  full_adder fa0(a[0], d ^ b[0], d, sum[0], carry[0]);
  full_adder fa1(a[1], d ^ b[1], carry[0], sum[1], carry[1]);
  full_adder fa2(a[2], d ^ b[2], carry[1], sum[2], carry[2]);
  full_adder fa3(a[3], d ^ b[3], carry[2], sum[3], carry[3]);
  full_adder fa4(a[4], d ^ 1'b0, carry[3], sum[4], carry[4]);
  full_adder fa5(a[5], d ^ 1'b0, carry[4], sum[5], carry[5]);
  full_adder fa6(a[6], d ^ 1'b0, carry[5], sum[6], carry[6]);
  full_adder fa7(a[7], d ^ 1'b0, carry[6], sum[7], cout);


endmodule

module full_adder(input a, b, cin, output sum, cout);
  

  assign sum = a ^ b ^ cin;
  assign cout = (a & b) | (cin & (a ^ b));

endmodule
