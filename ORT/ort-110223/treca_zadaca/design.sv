// Code your design here
// PROCES FOTOSINTEZE U BILJKAMA

module Fotosinteza (
  input i_clk,
  input i_rst_n,
  input svjetlost,
  input co2_prisutan,
  input h2o_prisutan,
  output proizvodnja_kiseonika_out
);
  
  
// Stanja 
typedef enum {
    Stanje_Pocetak = 3'b000,
    Stanje_Apsorpcije = 3'b001,
    Stanje_Pretvaranja = 3'b010,
    Stanje_Proizvodnja = 3'b011,
    Stanje_Kraj = 3'b100
} Stanje;

  Stanje stanje;
  reg proizvodnja_kiseonika;

  // Pocetna vrijednost
  initial begin
    stanje <= Stanje_Pocetak;
    proizvodnja_kiseonika <= 1'b0;
  end

  always @(posedge i_clk) begin
    if (0 == i_rst_n) begin // Reset
      stanje <= Stanje_Pocetak;
      proizvodnja_kiseonika <= 1'b0;
    end
    case (stanje) // Provjera stanja
      Stanje_Pocetak: begin
        if (svjetlost) begin
          stanje <= Stanje_Apsorpcije;
        end else begin
          stanje <= stanje;
        end
      end

      Stanje_Apsorpcije: begin
        if (h2o_prisutan) begin
          stanje <= Stanje_Pretvaranja;
        end else begin
          stanje <= stanje;
        end
      end

      Stanje_Pretvaranja: begin
        if (co2_prisutan) begin
          stanje <= Stanje_Proizvodnja;
        end else begin
          stanje <= stanje;
        end
      end

      Stanje_Proizvodnja: begin
        if (co2_prisutan) begin
          proizvodnja_kiseonika <= 1'b1;
          stanje <= Stanje_Kraj;
        end else begin
           stanje <= stanje;
        end
      end

      Stanje_Kraj: begin
        if(proizvodnja_kiseonika) begin
          proizvodnja_kiseonika <= 1'b0;
          stanje <= Stanje_Pocetak;
        end else begin 
          stanje <= stanje;
        end
      end

      default: stanje <= Stanje_Pocetak;
    endcase
  end
  assign proizvodnja_kiseonika_out = proizvodnja_kiseonika;

endmodule