#include "doctest.h"
#include "OrgChart.hpp"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
using namespace ariel;
TEST_CASE("good input"){
    OrgChart organization;
    // build of standard tree
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));         
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));      
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));         
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); 
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
    
    SUBCASE("check the iterator"){
        vector<string> level = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
        vector<string> reverse = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
        vector<string> preorder = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
        uint i = 0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {  
            CHECK(level.at(i) == *it);
            i++;
        }
        i = 0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {  
            CHECK(reverse.at(i) == *it);
            i++;
        }
        i = 0;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {  
            CHECK(preorder.at(i) == *it);
            i++;
        }
    }
    SUBCASE("change root"){
        CHECK_NOTHROW(organization.add_root("shlomo"));
        vector<string> level = {"shlomo", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
        vector<string> reverse = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "shlomo"};
        vector<string> preorder = {"shlomo", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
        uint i = 0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {  
            CHECK(level.at(i) == *it);
            i++;
        }
        i = 0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {  
            CHECK(reverse.at(i) == *it);
            i++;
        }
        i = 0;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {  
            CHECK(preorder.at(i) == *it);
            i++;
        }
    }
}
TEST_CASE("check the throws"){
    OrgChart organization;
    SUBCASE("empty chart"){
        CHECK_THROWS(organization.add_sub("shlomo", "shlomo"));
        CHECK_THROWS(organization.begin_level_order());
        CHECK_THROWS(organization.begin_reverse_order());
        CHECK_THROWS(organization.begin_preorder());
        CHECK_THROWS(organization.end_level_order());
        CHECK_THROWS(organization.reverse_order());
        CHECK_THROWS(organization.end_preorder());
    }
    SUBCASE("sub does not exist"){
        organization.add_root("shlomo");
        CHECK_THROWS(organization.add_sub("s", "shlomo"));
        CHECK_NOTHROW(organization.add_sub("shlomo", "noga"));
        CHECK_THROWS(organization.add_sub("noam", "noga"));
    }
    SUBCASE("illegal string"){
        CHECK_THROWS(organization.add_root("sh\nlomo"));
        organization.add_root("shlomo");
        string s = "";
        string& st = s;
        char c;
        for (int i = 0 ; i< 32 ; i++){
            c = i;
            st.push_back(c);
            CHECK_THROWS(organization.add_sub("shlomo", st));
            st.clear();
        }
    }
}