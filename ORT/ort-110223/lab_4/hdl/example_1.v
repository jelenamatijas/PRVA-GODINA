/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Inverter
 *
 *******************************************************************/
module inv(input i_A, output o_Y);
    assign o_Y = ~i_A;
endmodule : inv
/*******************************************************************/

/*******************************************************************
 *
 * JK flip-flop
 *
 *  J | K | Qn+1
 * ------------------------
 *  0 | 0 | Qn (no change)
 *  0 | 1 | 0 
 *  1 | 0 | 1
 *  1 | 1 | !Qn (toggles)
 *   
 *
 *******************************************************************/
module jk_ff(input i_clk, inout i_rst_n, input i_pre_n, input i_J, input i_K, output o_Q, output o_Q_n);
    reg q; 
    always @(posedge i_clk) begin
        if (0 == i_rst_n) begin
            q <= 1'b0;
        end else if (0 == i_pre_n) begin
            q <= 1'b1;
        end else begin
            case ({i_J, i_K}) 
                2'b00 : q <= q;
                2'b01 : q <= 1'b0;
                2'b10 : q <= 1'b1;
                2'b11 : q <= ~q;
                default : q <= q;
            endcase 
        end /* if (0 == rst_n) */
    end /* always @(posedge clk) */
    
    assign o_Q = q;
    assign o_Q_n = ~q;
    
endmodule : jk_ff
/*******************************************************************/

/*******************************************************************
 *
 * Example 1. Realizovati: D flip-flop pomoću JK flip-flopa
 *
 *******************************************************************/
module example_1_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);
    
    wire d;
    wire d_not;
    wire q;
    wire q_not;
    
    assign d = i_DATA[0];
    
    inv inv_inst (
        .i_A(d), 
        .o_Y(d_not)
    );
    
    jk_ff jk_ff_inst (
        .i_clk(i_clk), 
        .i_rst_n(i_rst_n), 
        .i_pre_n(1'b1), 
        .i_J(d), 
        .i_K(d_not), 
        .o_Q(q), 
        .o_Q_n(q_not)
    );
    
    assign o_DATA = {6'h0, q_not, q};
endmodule : example_1_gate
/*******************************************************************/

