/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 3. Projektovati mašinu sa konačnim brojem stanja za 
 *  sekvencijalnu mrežu kojom se
 *  realizuje funkcija obostranog brojača modula M=5.
 *
 * Note:
 *  Kontrolni signal UP/DOWN je mapiran na najnizi bit ulaznog
 *  signal i_DATA:
 *      up_down => i_DATA[0],
 *******************************************************************/
typedef enum{
S0 = 3'b000,
S1 = 3'b001,
S2 = 3'b010,
S3 = 3'b011,
S4 = 3'b100
} eFSM_state_t;


module task_3_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);
    wire t = i_DATA[0];
    eFSM_state_t current_state;
    eFSM_state_t next_state;
    reg [3:0] br;

//initial begin br <=0; end

    always @(posedge i_clk) begin
        if (0 == i_rst_n) begin
br<=0;
            current_state <= S0;
        end else begin
            current_state <= next_state;
        end
    end
   
    /**
     * Zadatak 2. Ispod opisati dato kolo projektovanom masinom stanja
     *            tako da dato kolo obavlja funkciju datu u zadatku!
     */
   
	always @(posedge i_clk)begin
		if (0 == i_rst_n)begin
			br<=0;
		end
		else begin
			if (t==1) begin
				if (br==4)
					br<=0;
				else br<=br + 1;
			end

		else begin
			if (br==0)
				br<=4;
			else br<=br-1;
			end
		end
	end

	assign o_DATA = {4'h0, br};
endmodule : task_3_gate
/*******************************************************************/

