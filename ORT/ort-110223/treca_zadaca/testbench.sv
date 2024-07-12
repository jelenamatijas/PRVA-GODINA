// Code your testbench here
// or browse Examples

module tb_Fotosinteza();

  reg i_clk;
  reg i_rst_n;
  reg svjetlost;
  reg co2_prisutan;
  reg h2o_prisutan;
  wire proizvodnja_kiseonika_out;

  Fotosinteza fotosinteza_init (
    .i_clk(i_clk),
    .i_rst_n(i_rst_n),
    .svjetlost(svjetlost),
    .co2_prisutan(co2_prisutan),
    .h2o_prisutan(h2o_prisutan),
    .proizvodnja_kiseonika_out(proizvodnja_kiseonika_out)
  );

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars();
    
    i_clk = 0;
    i_rst_n = 0;
    svjetlost = 0;
    co2_prisutan = 0;
    h2o_prisutan = 0;

    #5 i_rst_n = 1; 
    
    #10 svjetlost = 1; // Stanje_Pocetak
    #10; 

    #10 svjetlost = 1; // Stanje_Pocetak
    #10 h2o_prisutan = 1; // Stanje_Apsorpcije
    #10 h2o_prisutan = 0; // Stanje_Pretvaranja

    #10 svjetlost = 1; // Stanje_Pocetak
    #10 h2o_prisutan = 1; // Stanje_Apsorpcije
    #10 co2_prisutan = 1; // Stanje_Pretvaranja
    #10 co2_prisutan = 0; 

    #10 svjetlost = 1; // Stanje_Pocetak
    #10 h2o_prisutan = 1; // Stanje_Apsorpcije
    #10 co2_prisutan = 1; // Stanje_Pretvaranja
    #10; // Stanje_Proizvodnje
    #10;

    #10 svjetlost = 1; // Stanje_Pocetak
    #10 h2o_prisutan = 1; // Stanje_Apsorpcije
    #10 co2_prisutan = 1; // Stanje_Pretvaranja
    #10; // Stanje_Proizvodnje
    #10 co2_prisutan = 0; //Stanje_Kraj
    #10 h2o_prisutan = 0; 
    #10 svjetlost = 0; 

    #10 $finish;
  end

  always #5 i_clk = ~i_clk;

  always @(posedge i_clk) begin
    $display("Trenutno stanje: %d", fotosinteza_init.stanje);
  end

endmodule
