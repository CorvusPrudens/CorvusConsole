module dromdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [15:0] data
    );

    (* rom_style = "block" *) reg [15:0] dintern = 16'b0;

    always @( * ) begin
        case (address)
      16'h0000: dintern = 16'h00000002;
      16'h0001: dintern = 16'h00000002;
        default: dintern = 16'h0;
    endcase
  end

  assign data = dintern;

endmodule
