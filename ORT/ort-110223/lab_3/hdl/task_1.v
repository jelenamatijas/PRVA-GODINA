/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Task 1. Projektovati konvertor NBCD/7S (konvertor NBCD koda za 
 * prikaz cifara na 7-segmentnom displeju) korišćenjem standardnih 
 * logičkih kola. U slučaju pojave nedozvoljenog stanja na ulazu 
 * mreže na displeju ispisati odgovarajuću grešku.
 *
 *******************************************************************/

/*******************************************************************/
module nbcd_7s_converter(input [3 : 0] i_NBCD, output reg [6 : 0] o_SEG);
    always @(i_NBCD) begin
        /*
         * Funkcionalno opisati NBCD/7S Konvertor koda
         */
        case(i_NBCD)
		4'b0000:o_SEG=7'b1111110;
		4'b0001:o_SEG=7'b0110000;
		4'b0010:o_SEG=7'b1101101;
		4'b0011:o_SEG=7'b1111001;
		4'b0100:o_SEG=7'b0110011;
		4'b0101:o_SEG=7'b1011011;
		4'b0110:o_SEG=7'b1011111;
		4'b0111:o_SEG=7'b1110010;
		4'b1000:o_SEG=7'b1111111;
		4'b1001:o_SEG=7'b1111011;
		default:o_SEG=7'b1001111;
        endcase
    end // always @(i_NBCD)
endmodule : nbcd_7s_converter
/*******************************************************************/

/*******************************************************************/
module task_1_gate(
    input i_A,
    input i_B,
    input i_C,
    input i_D,
    output [7 : 0] o_Y
);
    
    /** 
     * Zadatak 1. Ispod instancirati odgovarajuce komponente i povezati 
     * ih tako da dato kolo obavlja funkciju datu u zadatku! 
     */
    wire [6:0]w_NBCD;
	nbcd_7s_converter nbcd_7s_converter_inst(.i_NBCD({i_A, i_B, i_C, i_D}), .o_SEG(w_NBCD));
	assign o_Y= {1'b0, w_NBCD};
endmodule : task_1_gate
/*******************************************************************/

