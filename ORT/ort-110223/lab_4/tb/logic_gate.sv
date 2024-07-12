
module logic_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);

    wire w_clk;
    wire w_rst_n;
    wire [7 : 0] w_in_data;
    wire [7 : 0] w_out_data;

    `ifdef __TASK_1__
        task_1_gate task_1_gate_inst (
                .i_clk(w_clk),
                .i_rst_n(w_rst_n),
                .i_DATA(w_in_data),
                .o_DATA(w_out_data)
            );
    `elsif __TASK_2__
        task_2_gate task_2_gate_inst (
                .i_clk(w_clk),
                .i_rst_n(w_rst_n),
                .i_DATA(w_in_data),
                .o_DATA(w_out_data)
            );
    `elsif __TASK_3__
        task_3_gate task_3_gate_inst (
                .i_clk(w_clk),
                .i_rst_n(w_rst_n),
                .i_DATA(w_in_data),
                .o_DATA(w_out_data)
            );
    `elsif __EXAMPLE_1__
        example_1_gate example_1_gate_inst (
                .i_clk(w_clk),
                .i_rst_n(w_rst_n),
                .i_DATA(w_in_data),
                .o_DATA(w_out_data)
            );
    `endif

    assign w_clk = i_clk;
    assign w_rst_n = i_rst_n;
    assign w_in_data = i_DATA;
    assign o_DATA = w_out_data;

endmodule

