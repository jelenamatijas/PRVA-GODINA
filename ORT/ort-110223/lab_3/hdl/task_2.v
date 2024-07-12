/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 2. Projektovati mrežu koja realizuje funkciju 
 * f(1) = {0, 4, 6, 7}. Na raspolaganju su jedan dekoder DEK 3/8 i 
 * jedno ILI logičko kolo sa potrebnim brojem ulaza
 *
 *******************************************************************/

/*******************************************************************/
module dec_3_8 (input [2 : 0] i_A, input i_CS, output reg [7 : 0] o_Y);
    always @(i_A or i_CS) begin
        if (1 == i_CS) begin
            o_Y = 0;
            /*
             * Funkcionalno opisati Dekoder 3/8
             */
			case(i_A)
			3'b000 : o_Y[0] = 1;
			3'b001 : o_Y[1] = 1;
			3'b010 : o_Y[2] = 1;
			3'b011 : o_Y[3] = 1;
            3'b100 : o_Y[4] = 1;	
            3'b101 : o_Y[5] = 1;
            3'b110 : o_Y[6] = 1;
            3'b111 : o_Y[7] = 1;
			//default:o_Y = 0;
            endcase
        end // if (1 == i_CS)
    end // always @(i_A or i_CS)
endmodule : dec_3_8
/*******************************************************************/

/*******************************************************************/
module or_4_gate (input i_A, input i_B, input i_C, input i_D, output o_Y);
    assign o_Y = i_A | i_B | i_C | i_D;
endmodule : or_4_gate
/*******************************************************************/

/*******************************************************************/
module task_2_gate (
    input i_A,
    input i_B,
    input i_C,
    input i_D,
    output [7 : 0] o_Y
);
    /** 
     * Zadatak 2. Ispod instancirati odgovarajuce komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     */
	wire [7:0]w_dec_3_8;
	wire w_or_4_gate;
	dec_3_8 dec_3_8_inst(.i_A({i_A, i_B, i_C}),.i_CS(1), .o_Y(w_dec_3_8));
	or_4_gate or_4_gate_inst(.i_A(w_dec_3_8[0]), .i_B(w_dec_3_8[4]), .i_C(w_dec_3_8[6]), .i_D(w_dec_3_8[7]), .o_Y(w_or_4_gate));
	assign o_Y = {7'h0, w_or_4_gate};
   
endmodule : task_2_gate
/*******************************************************************/

