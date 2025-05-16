#include <fstream>
#include "1_Quant.h"

void TestsToFile() {

    std::ofstream out("output.txt");
    
    Qubit q1_initial;                     
    Qubit q2_initial; q2_initial.setState(0.0, 1.0);  
    Qubit q3_initial; q3_initial.setState(Complex(3,-1), Complex(7,1)); 
    
    auto x = createXGate();
    auto y = createYGate();
    auto z = createZGate();
    auto h = createHGate();
    
    out << "Initial Qubit States:" << std::endl;
    out << "q1: " << q1_initial.toString() << std::endl;
    out << "q2: " << q2_initial.toString() << std::endl;
    out << "q3: " << q3_initial.toString() << std::endl << std::endl;
    
    ///////////////////////////////////////////////////////////////////////////////

    out << "X Gate Results:" << std::endl;
    State q1_x = x.apply(q1_initial.getState());
    Qubit tmp_q1_x; tmp_q1_x.setState(q1_x[0], q1_x[1]);
    out << "q1 after X: " << tmp_q1_x.toString() << std::endl;
    
    State q2_x = x.apply(q2_initial.getState());
    Qubit tmp_q2_x; tmp_q2_x.setState(q2_x[0], q2_x[1]);
    out << "q2 after X: " << tmp_q2_x.toString() << std::endl;
    
    State q3_x = x.apply(q3_initial.getState());
    Qubit tmp_q3_x; tmp_q3_x.setState(q3_x[0], q3_x[1]);
    out << "q3 after X: " << tmp_q3_x.toString() << std::endl << std::endl;
    
    ///////////////////////////////////////////////////////////////////////////////

    out << "Y Gate Results:" << std::endl;
    State q1_y = y.apply(q1_initial.getState());
    Qubit tmp_q1_y; tmp_q1_y.setState(q1_y[0], q1_y[1]);
    out << "q1 after Y: " << tmp_q1_y.toString() << std::endl;
    
    State q2_y = y.apply(q2_initial.getState());
    Qubit tmp_q2_y; tmp_q2_y.setState(q2_y[0], q2_y[1]);
    out << "q2 after Y: " << tmp_q2_y.toString() << std::endl;
    
    State q3_y = y.apply(q3_initial.getState());
    Qubit tmp_q3_y; tmp_q3_y.setState(q3_y[0], q3_y[1]);
    out << "q3 after Y: " << tmp_q3_y.toString() << std::endl << std::endl;
    
    ///////////////////////////////////////////////////////////////////////////////

    out << "Z Gate Results:" << std::endl;
    State q1_z = z.apply(q1_initial.getState());
    Qubit tmp_q1_z; tmp_q1_z.setState(q1_z[0], q1_z[1]);
    out << "q1 after Z: " << tmp_q1_z.toString() << std::endl;
    
    State q2_z = z.apply(q2_initial.getState());
    Qubit tmp_q2_z; tmp_q2_z.setState(q2_z[0], q2_z[1]);
    out << "q2 after Z: " << tmp_q2_z.toString() << std::endl;
    
    State q3_z = z.apply(q3_initial.getState());
    Qubit tmp_q3_z; tmp_q3_z.setState(q3_z[0], q3_z[1]);
    out << "q3 after Z: " << tmp_q3_z.toString() << std::endl << std::endl;
    
    /////////////////////////////////////////////////////////////////////////////////

    out << "H Gate Results:" << std::endl;
    State q1_h = h.apply(q1_initial.getState());
    Qubit tmp_q1_h; tmp_q1_h.setState(q1_h[0], q1_h[1]);
    out << "q1 after H: " << tmp_q1_h.toString() << std::endl;
    
    State q2_h = h.apply(q2_initial.getState());
    Qubit tmp_q2_h; tmp_q2_h.setState(q2_h[0], q2_h[1]);
    out << "q2 after H: " << tmp_q2_h.toString() << std::endl;
    
    State q3_h = h.apply(q3_initial.getState());
    Qubit tmp_q3_h; tmp_q3_h.setState(q3_h[0], q3_h[1]);
    out << "q3 after H: " << tmp_q3_h.toString() << std::endl << std::endl;

    ///////////////////////////////////////////////////////////////////////////////

    out << "CNOT Gate Results:" << std::endl;
    auto cnot = createCNOT();
    
    Qubit q1_cnot1 = q1_initial;
    Qubit q2_cnot1_target = q2_initial;
    cnot.apply(q1_cnot1, q2_cnot1_target);
    out << "q1 (control) and q2 (target):" << std::endl;
    out << "  control after CNOT: " << q1_cnot1.toString() << std::endl;
    out << "  target after CNOT: " << q2_cnot1_target.toString() << std::endl << std::endl;
    
    Qubit q2_cnot2 = q2_initial;
    Qubit q1_cnot2_target = q1_initial;
    cnot.apply(q2_cnot2, q1_cnot2_target);
    out << "q2 (control) and q1 (target):" << std::endl;
    out << "  control after CNOT: " << q2_cnot2.toString() << std::endl;
    out << "  target after CNOT: " << q1_cnot2_target.toString() << std::endl << std::endl;
    
    Qubit q1_cnot3 = q1_initial;
    Qubit q3_cnot3_target = q3_initial;
    cnot.apply(q1_cnot3, q3_cnot3_target);
    out << "q1 (control) and q3 (target):" << std::endl;
    out << "  control after CNOT: " << q1_cnot3.toString() << std::endl;
    out << "  target after CNOT: " << q3_cnot3_target.toString() << std::endl << std::endl;

    Qubit q2_cnot4 = q2_initial;
    Qubit q3_cnot4_target = q3_initial;
    cnot.apply(q2_cnot4, q3_cnot4_target);
    out << "q2 (control) and q3 (target):" << std::endl;
    out << "  control after CNOT: " << q2_cnot4.toString() << std::endl;
    out << "  target after CNOT: " << q3_cnot4_target.toString() << std::endl << std::endl;
    
    out.close();
}