/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/
 
/*******************************************************************
 *
 * JK flip-flop
 *
 * RSTn | SETn | J | K | Qn+1
 * -------------------------------------
 *   0  |  x   | x | x | 0
 *   1  |  0   | x | x | 1
 * -------------------------------------
 *   1  |  1   | 0 | 0 | Qn (no change)
 *   1  |  1   | 0 | 1 | 0 
 *   1  |  1   | 1 | 0 | 1
 *   1  |  1   | 1 | 1 | !Qn (toggles)
 *
 *******************************************************************/
module jk_ff(input i_clk, input i_rst_n, input i_pre_n, input i_J, input i_K, output o_Q, output o_Q_n);
    reg q; 
    always @(negedge i_clk or negedge i_rst_n or negedge i_pre_n) begin
   
        /* Reset */
        
        /* Set */
        
        /* JK ff logic */
        
    end /* always @(posedge clk) */
    
    /* Mapiranje izlaza */ 
    
endmodule : jk_ff
/*******************************************************************/

/*******************************************************************
 *
 * NAND2 
 *
 *******************************************************************/
module nand_2_gate(input i_A, input i_B, output o_Y);
    assign o_Y = ~(i_A & i_B);
endmodule : nand_2_gate
/*******************************************************************/

/*******************************************************************
 *
 * Zadatak 3. Projektovati (realizovati) dekadni serijski brojač.
 *
 *******************************************************************/
module task_3_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
); 
    /** 
     * Zadatak 3. Ispod instancirati odgovarajuce komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     * 
     * Ili funkcionalno opisati kolo da obavlja funkciju datu u zadatku!
     *
     */
	reg [3:0]cnt;
    always @(posedge i_clk) begin
		if(0==i_rst_n)begin
			cnt<=0;
		end else begin
			if(9==cnt)
				cnt<=0;
			else
				cnt<=cnt+1;
		end
	end
	assign o_DATA = {4'h0, cnt};
endmodule : task_3_gate
/*******************************************************************/


