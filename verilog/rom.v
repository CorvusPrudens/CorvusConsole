`include "romdata.v"

module rom(
    input wire CLK,
    input wire [15:0] address,
    output wire [31:0] data
  );

  // This will be a placeholder for actual
  // writable ROM that we'll figure out later
  romdata ROMDATA(
    .CLK(CLK),
    .address(address),
    .data(data)
    );

endmodule
