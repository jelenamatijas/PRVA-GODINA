/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Multiplexer 4/1
 *   
 *******************************************************************/
module mux_4_1(input i_I3, input i_I2, input i_I1, input i_I0, input [1 : 0] i_SEL, output reg o_Y);
    always @(i_I3, i_I2, i_I1, i_I0, i_SEL) begin
        /*
         * Funkcionalno opisati Multipleksor 4/1
         */
        case (i_SEL)
	        2'b00 : o_Y = i_I0;
	        2'b01 : o_Y = i_I1;
            2'b10 :	o_Y = i_I2;
            2'b11 : o_Y = i_I3;
	        default : o_Y = 0;
	    endcase
    end // always @(i_I3, i_I2, i_I1, i_I0, i_SEL)
endmodule : mux_4_1
/*******************************************************************/

/*******************************************************************
 *
 * D flip-flop
 *
 *  RSTn == 0 => Qn = 0
 *  RSTn == 1 => Qn = Dn-1
 *
 *******************************************************************/
module d_ff(input i_clk, input i_rst_n, input i_D, output o_Q, output o_Q_n);
    reg q;
    always @(posedge i_clk) begin
        /* Reset */
        /* D ff logic */
        
    end /* always @(posedge clk) */
    
    /* Mapiranje izlaza */ 
    
endmodule : d_ff
/*******************************************************************/

/*******************************************************************
 *
 * Zadatak 2. Realizovati, odn. projektovati obostrani pomjerački
 *  registar. Korišćenjem šeme nacrtane u pripremi korišćenjem
 *  D flip-flopova i multipleksora 4/1 ili funkcionalnim opisom. 
 *
 *  Režim rada registra se kontroliše
 *  preko kontrolnih signala S1 i S0:
 *      - S1S0 = 2’b00 => registar zadržava prethodno stanje;
 *      - S1S0 = 2’b01 => pod dejstvom takta u registar se paralelno 
 *                          upisuje informacija ABCD;
 *      - S1S0 = 2’b10 => registar radi kao pomjerački registar ulijevo;
 *      - S1S0 = 2’b11 => registar radi kao pomjerački registar udesno.
 *
 * Note:
 *  - Kontrolni signali S1 i S0 su mapirani na najvisa dva bita ulaznog
 *  signal i_DATA:
 *      S1 => i_DATA[7],
 *      S0 => i_DATA[6],
 *  - Lijevi ulazni signal sift registra - Il - je mapiran na 5 bit 
 *  ulaznog signala i_DATA:
 *      Il => i_DATA[5];
 *  - Desni ulazni signal sift registra - Id - je mapiran na 4 bit 
 *  ulaznon signala i_DATA:
 *      Id => i_DATA[4];
 *  - Ulazni 4-bitni vektor - I3I2I1I0 - je mapiran na najniza 4 bita
 *  ulaznog signala i_DATA:
 *      I3 => i_DATA[3],
 *      I2 => i_DATA[2],
 *      I1 => i_DATA[1],
 *      I0 => i_DATA[0];
 *******************************************************************/
module task_2_gate(
    input i_clk,
    input i_rst_n,
    input [7 : 0] i_DATA,
    output [7 : 0] o_DATA
);
    /** 
     * Zadatak 2. Ispod instancirati odgovarajuće komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     * 
     * Ili funkcionalno opisati kolo da obavlja funkciju datu u zadatku!
     */
	reg q0 = 1'b0, q1 = 1'b0, q2 = 1'b0, q3 = 1'b0; 
    wire s1 = i_DATA[7], s2 = i_DATA[6];
    
    always @(posedge i_clk) begin
        if (0 == i_rst_n) begin
            q0 <= 0;
            q1 <= 0;
            q2 <= 0;
            q3 <= 0;
        end else begin 
            case ({s1, s2})
                2'b00:
                    begin
                        q0 <= q0;
                        q1 <= q1;
                        q2 <= q2;
                        q3 <= q3;
                    end
                2'b01:
                    begin 
                        q0 <= i_DATA[3];
                        q1 <= i_DATA[2];
                        q2 <= i_DATA[1];
                        q3 <= i_DATA[0];
                    end
                2'b10:
                    begin
                        q0 <= q1;
                        q1 <= q2;
                        q2 <= q3;
                        q3 <= i_DATA[4];
                    end
                2'b11:
                    begin
                        q0 <= i_DATA[5];
                        q1 <= q0;
                        q2 <= q1;
                        q3 <= q2;
                    end
            endcase
        end
    end // always @(posedge i_clk)
    
    assign o_DATA = {4'h0, q0, q1, q2, q3}; 
endmodule : task_2_gate
/*******************************************************************/

