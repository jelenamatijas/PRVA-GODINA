
module logic_gate(
    input i_A,
    input i_B,
    input i_C,
    input i_D,
    output [7 : 0] o_Y
);

    wire w_a;
    wire w_b;
    wire w_c;
    wire w_d;
    wire [7 : 0] w_y;

    `ifdef __TASK_1__
        task_1_gate task_1_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .i_C(w_c),
                .i_D(w_d),
                .o_Y(w_y)
            );
    `elsif __TASK_2__
        task_2_gate task_2_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .i_C(w_c),
                .i_D(w_d),
                .o_Y(w_y)
            );
    `elsif __TASK_3__
        task_3_gate task_3_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .i_C(w_c),
                .i_D(w_d),
                .o_Y(w_y)
            );
    `elsif __EXAMPLE_1__
        example_1_gate example_1_gate_inst (
                .i_A(w_a),
                .i_B(w_b),
                .i_C(w_c),
                .i_D(w_d),
                .o_Y(w_y)
            );
    `endif

    assign w_a = i_A;
    assign w_b = i_B;
    assign w_c = i_C;
    assign w_d = i_D;
    assign o_Y = w_y;

endmodule

