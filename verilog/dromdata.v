module dromdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [15:0] data
    );

    (* rom_style = "block" *) reg [15:0] dintern = 16'b0;

    always @( * ) begin
        case (address)
      16'h0000: dintern = 16'h0000004C;
      16'h0001: dintern = 16'h0000006F;
      16'h0002: dintern = 16'h00000072;
      16'h0003: dintern = 16'h00000065;
      16'h0004: dintern = 16'h0000006D;
      16'h0005: dintern = 16'h00000020;
      16'h0006: dintern = 16'h00000069;
      16'h0007: dintern = 16'h00000070;
      16'h0008: dintern = 16'h00000073;
      16'h0009: dintern = 16'h00000075;
      16'h000A: dintern = 16'h0000006D;
      16'h000B: dintern = 16'h00000000;
      16'h000C: dintern = 16'h00000064;
      16'h000D: dintern = 16'h0000006F;
      16'h000E: dintern = 16'h0000006C;
      16'h000F: dintern = 16'h0000006F;
      16'h0010: dintern = 16'h00000072;
      16'h0011: dintern = 16'h00000065;
      16'h0012: dintern = 16'h00000073;
      16'h0013: dintern = 16'h00000000;
      16'h0014: dintern = 16'h00000048;
      16'h0015: dintern = 16'h00000065;
      16'h0016: dintern = 16'h0000006C;
      16'h0017: dintern = 16'h0000006C;
      16'h0018: dintern = 16'h0000006F;
      16'h0019: dintern = 16'h0000002C;
      16'h001A: dintern = 16'h00000020;
      16'h001B: dintern = 16'h00000077;
      16'h001C: dintern = 16'h0000006F;
      16'h001D: dintern = 16'h00000072;
      16'h001E: dintern = 16'h0000006C;
      16'h001F: dintern = 16'h00000064;
      16'h0020: dintern = 16'h00000021;
      16'h0021: dintern = 16'h00000000;
        default: dintern = 16'h0;
    endcase
  end

  assign data = dintern;

endmodule
