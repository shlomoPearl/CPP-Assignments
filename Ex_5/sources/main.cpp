// #include <iostream>
// #include "OrgChart.cpp"
// using namespace std;
// using namespace ariel;
//  int main(){
//     OrgChart organization1;
//     organization1.add_root("CEO")
//       .add_sub("CEO", "CTO")         
//       .add_sub("CEO", "CFO")         
//       .add_sub("CEO", "COO")        
//       .add_sub("CTO", "VP_SW") 
//       .add_sub("COO", "VP_BI");  
//     cout << organization1 << endl;   

//     OrgChart organization2;
//     organization2.add_root("shlomo")
//         .add_sub("shlomo", "dovi")
//         .add_sub("dovi", "gil");
//     cout << endl << organization2 << endl << endl;

//     OrgChart organization3;
//     organization3.add_root("AAA")
//         .add_sub("AAA", "BBB")
//         .add_sub("AAA", "CCC")
//         .add_sub("AAA", "DDD")
//         .add_sub("BBB", "bbb")
//         .add_sub("CCC", "ccc")
//         .add_sub("DDD", "ddd");
//     cout << organization3 << endl;
//     for (auto element : organization3) { // equivilent to level order
//         cout << element << " ";
//     }
//     cout << endl;
//     for (auto it = organization3.begin_level_order(); it != organization3.end_level_order(); ++it) {  
//         cout << (*it) << " ";
//     }
//     cout << endl;
//     for (auto it = organization3.begin_reverse_order(); it != organization3.reverse_order(); ++it) {
//         cout << (*it) << " " ;
//     }
//     cout << endl;
//     for (auto it=organization3.begin_preorder(); it!=organization3.end_preorder(); ++it) {
//         cout << (*it) << " " ;
//     }  
//     cout << endl;
//     return 0;
//  }