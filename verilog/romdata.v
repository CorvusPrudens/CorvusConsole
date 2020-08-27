module romdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [31:0] data
  );

  // Xilinx style block ram directive
  (* rom_style = "block" *) reg [31:0] dintern = 32'b0;

  always @( * ) begin
    case (address)
      16'h0000: dintern = 32'h00010006;
      16'h0001: dintern = 32'h00002006;
      16'h0002: dintern = 32'h00004006;
      16'h0003: dintern = 32'h00008006;
      16'h0004: dintern = 32'h80000016;
      16'h0005: dintern = 32'h0014085C;
      16'h0006: dintern = 32'h0000401A;
      16'h0007: dintern = 32'h00000418;
      16'h0008: dintern = 32'h0000211A;
      16'h0009: dintern = 32'h00030008;
      16'h000A: dintern = 32'h00086042;
      16'h000B: dintern = 32'h00030188;
      16'h000C: dintern = 32'h0002821A;
      16'h000D: dintern = 32'h00FF0216;
      16'h000E: dintern = 32'h0010085C;
      16'h000F: dintern = 32'h00040050;
      16'h0010: dintern = 32'h0003A004;
      16'h0011: dintern = 32'h0200A2AE;
      16'h0012: dintern = 32'h001000DC;
      16'h0013: dintern = 32'h00040050;
      16'h0014: dintern = 32'h00010006;
      16'h0015: dintern = 32'h00002006;
      16'h0016: dintern = 32'h00004006;
      16'h0017: dintern = 32'h00040050;
      default: dintern = 32'h0;
    endcase
  end

  assign data = dintern;

endmodule
