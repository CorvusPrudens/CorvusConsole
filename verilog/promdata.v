module promdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [31:0] data
  );

  // Xilinx style block ram directive
  (* rom_style = "block" *) reg [31:0] dintern = 32'b0;

  always @( * ) begin
    case (address)
      16'h0000: dintern = 32'h000A0007;
      16'h0001: dintern = 32'h00032007;
      16'h0002: dintern = 32'h00004007;
      16'h0003: dintern = 32'h00000414;
      16'h0004: dintern = 32'h0006085C;
      16'h0005: dintern = 32'h00050050;
      16'h0006: dintern = 32'h00010007;
      16'h0007: dintern = 32'h00030008;
      16'h0008: dintern = 32'h00030108;
      16'h0009: dintern = 32'h00050050;
      default: dintern = 32'h0;
    endcase
  end

  assign data = dintern;

endmodule
