/*******************************************************************
 *
 * ETF Comment header
 *
 *******************************************************************/

/*******************************************************************
 *
 * Logic gate: OR -> Y = A | B
 *  
 *     -------------
 *     | A | B | Y |
 *     -------------
 *     | 0 | 0 | 0 |
 *     -------------
 *     | 0 | 1 | 1 |
 *     -------------
 *     | 1 | 0 | 1 |
 *     -------------
 *     | 1 | 1 | 1 |
 *     -------------
 *
 *******************************************************************/
module or_gate(
    input i_A, 
    input i_B, 
    output o_Y
);
    /** Zadatak 2. Ispod unijeti logicku funkciju "OR" logickog kola! */
    assign o_Y = i_A | i_B;
endmodule

