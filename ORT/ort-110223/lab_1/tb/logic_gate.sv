
module logic_gate(
    input i_A, 
    input i_B, 
    output o_Y
);

    wire w_a;
    wire w_b;
    wire w_y;

    `ifdef __OR__
        or_gate or_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `elsif __NOR__
        nor_gate nor_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `elsif __AND__
        and_gate and_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `elsif __NAND__
        nand_gate nand_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `elsif __XOR__
        xor_gate xor_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `else
        or_gate or_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .o_Y(w_y)
            );
    `endif

    assign w_a = i_A;
    assign w_b = i_B;
    assign o_Y = w_y;

endmodule

