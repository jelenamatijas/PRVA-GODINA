/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 2. Projektovati mašinu sa konačnim brojem stanja za sekvencijalnu mežu kojom se
 *  realizuje funkcija obostranog pomjeračkog registra. Režim rada registra se kontroliše
 *  preko kontrolnih signala S1 i S0:
 *      - S1S0 = 2’b00 => registar zadržava prethodno stanje;
 *      - S1S0 = 2’b01 => pod dejstvom takta u registar se paralelno upisuje informacija ABCD;
 *      - S1S0 = 2’b10 => registar radi kao pomjerački registar ulijevo;
 *      - S1S0 = 2’b11 => registar radi kao pomjerački registar udesno.
 *
 * Note:
 *  Kontrolni signali S1 i S0 su mapirani na najvisa dva bita ulaznog
 *  signal i_DATA:
 *      S1 => i_DATA[7],
 *      S0 => i_DATA[6],
 *  Lijevi ulazni signal sift registra - Il - je mapiran na 5 bit 
 *  ulaznog signala i_DATA:
 *      Il => i_DATA[5];
 *  Desni ulazni signal sift registra - Id - je mapiran na 4 bit 
 *  ulaznon signala i_DATA:
 *      Id => i_DATA[4];
 *  Ulazni 4-bitni vektor - I3I2I1I0 - je mapiran na najniza 4 bita
 *  ulaznog signala i_DATA:
 *      I3 => i_DATA[3],
 *      I2 => i_DATA[2],
 *      I1 => i_DATA[1],
 *      I0 => i_DATA[0];
 *******************************************************************/
typedef enum{
	IDLE = 4'b0001,
	LOAD = 4'b0010,
	SHR = 4'b0100,
	SHL = 4'b1000
} eFSM_state_t;

module task_2_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);
    /** 
     * Zadatak 2. Ispod instancirati odgovarajuce komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     */
    eFSM_state_t state;
	wire [1:0] OP;
	reg w_left_data;
	reg w_right_data;
	reg [3:0] input_data;
	reg [3:0] reg_data;
	assign OP = {i_DATA[7], i_DATA[6]};
	
	always @(posedge i_clk) begin
        if (0 == i_rst_n) begin
            w_left_data <= 1'b0;
			w_right_data <= 1'b0;
			input_data<=0;
        end else begin 
            w_left_data <= i_DATA[5];
			w_right_data <= i_DATA[4];
			input_data<=i_DATA[3:0];
        end
    end // always @(posedge i_clk)
	
	/**********************************************************************************/
	
	always @(posedge i_clk) begin
        if(0 == i_rst_n)begin
			state <= IDLE;
			reg_data <= 0;
        end else begin 
			case (state)
				IDLE: begin
					reg_data<=reg_data;
					if(2'b11 == OP) begin
						state <=SHR;
					end else if(2'b10 == OP)begin
						state <= SHL;
					end else if(2'b01 == OP)begin
						state <=LOAD;
					end else begin
						state <= IDLE;
					end
				end
				LOAD: begin
					reg_data<=input_data;
					if(2'b11 == OP) begin
						state <=SHR;
					end else if(2'b10 == OP)begin
						state <= SHL;
					end else if(2'b00 == OP)begin
						state <=IDLE;
					end else begin
						state <= LOAD;
					end
				end
				SHR: begin
					reg_data<={w_left_data, reg_data[3:1]};
					if(2'b00 == OP) begin
						state <=IDLE;
					end else if(2'b10 == OP)begin
						state <= SHL;
					end else if(2'b01 == OP)begin
						state <=LOAD;
					end else begin
						state <= SHR;
					end
				end
				SHL: begin
					reg_data<={reg_data[2:0], w_right_data};
					if(2'b00 == OP) begin
						state <=IDLE;
					end else if(2'b11 == OP)begin
						state <= SHR;
					end else if(2'b01 == OP)begin
						state <=LOAD;
					end else begin
						state <= SHL;
					end
				end
			endcase
		end
    end // always @(posedge i_clk)
	assign o_DATA = {4'h0, reg_data};
endmodule : task_2_gate
/*******************************************************************/

