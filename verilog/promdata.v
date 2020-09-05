module promdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [31:0] data
  );

  // Xilinx style block ram directive
  (* rom_style = "block" *) reg [31:0] dintern = 32'b0;

  always @( * ) begin
    case (address)
      16'h0000: dintern = 32'h0001E007;
      16'h0001: dintern = 32'h0000C007;
      16'h0002: dintern = 32'h0000000D;
      16'h0003: dintern = 32'h00000017;
      16'h0004: dintern = 32'h000B045C;
      16'h0005: dintern = 32'h00030008;
      16'h0006: dintern = 32'h00082043;
      16'h0007: dintern = 32'h00030088;
      16'h0008: dintern = 32'h0001C31B;
      16'h0009: dintern = 32'h0000000D;
      16'h000A: dintern = 32'h00030050;
      16'h000B: dintern = 32'h00000311;
      16'h000C: dintern = 32'h000B0050;
      default: dintern = 32'h0;
    endcase
  end

  assign data = dintern;

endmodule
