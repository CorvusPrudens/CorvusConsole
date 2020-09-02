module dromdata(
    input wire CLK,
    input wire [15:0] address,
    output wire [15:0] data
    );

    (* rom_style = "block" *) reg [15:0] dintern = 16'b0;

    always @( * ) begin
        case (address)
        default: dintern = 16'h0;
    endcase
  end

  assign data = dintern;

endmodule
