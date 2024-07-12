

`define TOP_ID                  ("ORT-2023")

function bit check_logic(bit _a, 
                            bit _b,
                            bit _y
                            );
    bit ret_val;
    
    `ifdef __OR__
        ret_val = ((_a | _b) == _y) ? 0 : 1;
    `elsif __NOR__
        ret_val = ((~(_a | _b)) == _y) ? 0 : 1;
    `elsif __AND__
        ret_val = ((_a & _b) == _y) ? 0 : 1;
    `elsif __NAND__
        ret_val = ((~(_a & _b)) == _y) ? 0 : 1;
    `elsif __XOR__
        ret_val = ((_a ^ _b) == _y) ? 0 : 1;
    `else
        $display("%s: Logic gate: UNDEFINED", `TOP_ID);
    `endif
    
    return (ret_val);
endfunction : check_logic

module top;

    logic a;
    logic b;
    logic y;
    
    bit start;
    
    integer fd;
    string fname;
    string lname;
    string str;
    bit check_status;
    int status;

    logic_gate logic_gate_inst (
            .i_A(a),
            .i_B(b),
            .o_Y(y)
        );

    initial begin
        start = 0;
        $display("%s: ====================================================", `TOP_ID);
        `ifdef __OR__
            $display("%s: Logic gate: OR -> Y = A | B", `TOP_ID);
            fname = "./results/task_2.log"; //"or";
            lname = "OR";
        `elsif __NOR__
            $display("%s: Logic gate: NOR -> Y = !(A | B)", `TOP_ID);
             fname = "./results/task_3.log"; //"nor";
             lname = "NOR";
        `elsif __AND__
            $display("%s: Logic gate: AND -> Y = A & B", `TOP_ID);
             fname = "./results/and.log"; //"and";
             lname = "AND";
        `elsif __NAND__
            $display("%s: Logic gate: NAND -> Y = !(A & B)", `TOP_ID);
             fname = "./results/task_1.log"; //"nand";
             lname = "NAND";
        `elsif __XOR__
            $display("%s: Logic gate: XOR -> Y = A ^ B", `TOP_ID);
             fname = "./results/task_4.log"; //"xor";
             lname = "XOR";
        `else
            $display("%s: Logic gate: UNDEFINED", `TOP_ID);
        `endif
        fd = $fopen(fname, "w");
        $fdisplay(fd, "task:", lname);
        start = 1;
    end
        
    initial begin
        a = 0;
        b = 0;
        status = 0;
        wait (1 == start);
    
        $display("%s: ====================================================", `TOP_ID);
        //$display("%s: --------------------------------------------------", `TOP_ID);
        $display("%s: \t-------------", `TOP_ID);
        $display("%s: \t| A | B | Y |", `TOP_ID);
        $display("%s: \t-------------", `TOP_ID);
        //$display("%s: -------------", `TOP_ID);
        #5ns;
        a = 0;
        b = 0;
        #5ns;
        check_status = check_logic(a, b, y);
        status += check_status;
        str = $sformatf("%b %b %b - %s",
                        a, b, y, ((0 == check_status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: \t| %b | %b | %b |", `TOP_ID,
                    a, b, y);
        $display("%s: \t-------------", `TOP_ID);
        a = 0;
        b = 1;
        #5ns;
        check_status = check_logic(a, b, y);
        status += check_status;
        str = $sformatf("%b %b %b - %s",
                        a, b, y, ((0 == check_status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: \t| %b | %b | %b |", `TOP_ID,
                    a, b, y);
        $display("%s: \t-------------", `TOP_ID);
        a = 1;
        b = 0;
        #5ns;
        check_status = check_logic(a, b, y);
        status += check_status;
        str = $sformatf("%b %b %b - %s",
                        a, b, y, ((0 == check_status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: \t| %b | %b | %b |", `TOP_ID,
                    a, b, y);
        $display("%s: \t-------------", `TOP_ID);
        a = 1;
        b = 1;
        #5ns;
        check_status = check_logic(a, b, y);
        status += check_status;
        str = $sformatf("%b %b %b - %s",
                        a, b, y, ((0 == check_status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: \t| %b | %b | %b |", `TOP_ID,
                    a, b, y);
        $display("%s: \t-------------", `TOP_ID);
        //$display("%s: --------------------------------------------------", `TOP_ID);
        $display("%s: ====================================================", `TOP_ID);
        str = $sformatf("final:%s", ((0 == status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: FINAL - %s", `TOP_ID,
                    ((0 == status) ? "OK" : "NOK"));
        $finish();
    end

endmodule : top
