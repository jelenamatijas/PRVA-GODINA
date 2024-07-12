/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 1. Projektovati mašinu sa konačnim brojem stanja za 
 *  sekvencijalnu mrežu kojom se realizuje funkcija 
 *  uključenja/isključenja nekog izlaznog uređaja 
 *  (npr. dioda koja emituje svjetlost – LED dioda).
 *
 *******************************************************************/

typedef enum {
    S00 = 4'b0001,
    S11 = 4'b0010,
    S20 = 4'b0100,
    S31 = 4'b1000
} eFSM_state_t; 

module task_1_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);
    eFSM_state_t current_state;
    eFSM_state_t next_state;
    
    always @(posedge i_clk) begin
        if (0 == i_rst_n) begin
            current_state <= S00;
        end else begin
            current_state <= next_state;
        end /* if (0 == i_rst_n) */
    end /* always @(posedge i_clk) */
    
    /** 
     * Zadatak 1. Ispod opisati dato kolo projektovanom masinom stanja 
     *            tako da dato kolo obavlja funkciju datu u zadatku! 
     */
	wire t;
	assign t = i_DATA[0];
	reg out;
	
	always@(posedge i_clk)begin	
		if(0 == i_rst_n)begin
			out<=0;
		end else begin
			if(t == 1)
				out<=0;
			else 
				out<=1;
		end
	end
	assign o_DATA = {7'h0, out};
    
endmodule : task_1_gate
/*******************************************************************/

