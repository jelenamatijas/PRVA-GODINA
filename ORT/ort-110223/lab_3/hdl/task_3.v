/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 3. Projektovati mrežu koja realizuje funkciju
 * f(D,C,B,A) = ∑(3,5,6,7,9,10,11,12,13,14,15). Na raspolaganju je 
 * multiplekser MX 4/1 i standardna logička kola.
 *
 *******************************************************************/

/*******************************************************************/
module mux_4_1(input i_I3, input i_I2, input i_I1, input i_I0, input [1 : 0] i_SEL, output reg o_Y);
    always @(i_I3, i_I2, i_I1, i_I0, i_SEL) begin
        /*
         * Funkcionalno opisati Multipleksor 4/1
         */
		 
		case(i_SEL)
			2'b00:o_Y=i_I0;
			2'b01:o_Y=i_I1;
			2'b10:o_Y=i_I2;
			2'b11:o_Y=i_I3;
			default:o_Y=0;
		endcase
        
    end // always @(i_I3, i_I2, i_I1, i_I0, i_SEL)
endmodule : mux_4_1
/*******************************************************************/

/*******************************************************************/
module or_2_gate(input i_A, input i_B, output o_Y);
    assign o_Y = i_A | i_B;
endmodule : or_2_gate
/*******************************************************************/

/*******************************************************************/
module and_2_gate(input i_A, input i_B, output o_Y);
    assign o_Y = i_A & i_B;
endmodule : and_2_gate
/*******************************************************************/

/*******************************************************************/

module task_3_gate(
    input i_A,
    input i_B,
    input i_C,
    input i_D,
    output [7 : 0] o_Y
);
    /** 
     * Zadatak 3. Ispod instancirati odgovarajuce komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     */
	wire w_or_y;
	wire w_and_y;
	wire [1:0] w_sel;
	wire w_mux_y;
	assign w_sel = {i_B, i_A};
	
	
	and_2_gate and_2_gate_inst(.i_A(i_D), .i_B(i_C), .o_Y(w_and_y));
	or_2_gate or_2_gate_inst(.i_A(i_D), .i_B(i_C), .o_Y(w_or_y));
	mux_4_1 mux_4_1_inst(.i_I3(1'b1), .i_I2(w_or_y), .i_I1(w_or_y), .i_I0(w_and_y), .i_SEL(w_sel), .o_Y(w_mux_y));
    assign o_Y = {0,w_mux_y};
endmodule : task_3_gate
/*******************************************************************/

