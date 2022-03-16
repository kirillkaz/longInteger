#include "gtest/gtest.h"
#include "../BigInt/src/bigInt.cpp"

void RUN(){
    RUN_ALL_TESTS();
}
//tests 1
TEST(bigIntTest,plus){
    //test 1
    bigInt num1,num2;
    std::string resultTest;
    num1.num = "123";
    num2.num = "321";
    num1 = num1+num2;
    resultTest = "444";

    EXPECT_EQ(num1.num,resultTest);

    //test 2
    num1.num = "123333";
    num2.num = "321";
    num1 = num1+num2;
    resultTest = "123654";

    EXPECT_EQ(num1.num,resultTest);

    //test 3
    num1.num = "321";
    num2.num = "123333";
    num1 = num1+num2;
    resultTest = "123654";

    EXPECT_EQ(num1.num,resultTest);

    //test 4
    num1.num = "99999";
    num2.num = "1";
    num1 = num1+num2;
    resultTest = "100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 5
    num1.num = "99999";
    num2.num = "-1";
    num1 = num1+num2;
    resultTest = "99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 6
    num1.num = "-99999";
    num2.num = "1";
    num1 = num1+num2;
    resultTest = "-99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 7
    num1.num = "-1";
    num2.num = "99999";
    num1 = num1+num2;
    resultTest = "99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 8
    num1.num = "1";
    num2.num = "-99999";
    num1 = num1+num2;
    resultTest = "-99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 9
    num1.num = "99999";
    num2.num = "1";
    num1 = num1+num2;
    resultTest = "100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 10
    num1.num = "-99999";
    num2.num = "-99999";
    num1 = num1+num2;
    resultTest = "-199998";

    EXPECT_EQ(num1.num,resultTest);

    //test 11
    num1.num = "99999";
    num2.num = "-99999";
    num1 = num1+num2;
    resultTest = "0";

    EXPECT_EQ(num1.num,resultTest);

    //test 12
    num1.num = "5678897654344567543567543567865456756788976543445675435675435678654567567889765434456754356754356786545675678897654344567543567543567865456756788976543445675435675435678654567";
    num2.num = "3456789876543567897654356789765435678976534567898765435678976543567897654356789765345678987654356789765435678976543567897653456789876543567897654356789765435678976534567898765435678976543567897654356789765";
    num1 = num1+num2;
    resultTest = "3456789876543567897654356789771114576630879135442332979246842000324686630900235440781354423333011357333325444411000322254407813576422219246795308701357309003222544400024655554412222422219003573090035444332";

    EXPECT_EQ(num1.num,resultTest);
}

//tests 2
TEST(bigIntTest,minus){
    //test 1
    bigInt num1,num2;
    std::string resultTest;
    num1.num = "123";
    num2.num = "321";
    num1 = num1-num2;
    resultTest = "-198";

    EXPECT_EQ(num1.num,resultTest);

    //test 2
    num1.num = "123333";
    num2.num = "321";
    num1 = num1-num2;
    resultTest = "123012";

    EXPECT_EQ(num1.num,resultTest);

    //test 3
    num1.num = "321";
    num2.num = "123333";
    num1 = num1-num2;
    resultTest = "-123012";

    EXPECT_EQ(num1.num,resultTest);

    //test 4
    num1.num = "99999";
    num2.num = "1";
    num1 = num1-num2;
    resultTest = "99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 5
    num1.num = "99999";
    num2.num = "-1";
    num1 = num1-num2;
    resultTest = "100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 6
    num1.num = "-99999";
    num2.num = "1";
    num1 = num1-num2;
    resultTest = "-100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 7
    num1.num = "-1";
    num2.num = "99999";
    num1 = num1-num2;
    resultTest = "-100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 8
    num1.num = "1";
    num2.num = "-99999";
    num1 = num1-num2;
    resultTest = "100000";

    EXPECT_EQ(num1.num,resultTest);

    //test 9
    num1.num = "99999";
    num2.num = "1";
    num1 = num1-num2;
    resultTest = "99998";

    EXPECT_EQ(num1.num,resultTest);

    //test 10
    num1.num = "-99999";
    num2.num = "-99999";
    num1 = num1-num2;
    resultTest = "0";

    EXPECT_EQ(num1.num,resultTest);

    //test 11
    num1.num = "99999";
    num2.num = "-99999";
    num1 = num1-num2;
    resultTest = "199998";

    EXPECT_EQ(num1.num,resultTest);

    //test 12
    num1.num = "5678897654344567543567543567865456756788976543445675435675435678654567567889765434456754356754356786545675678897654344567543567543567865456756788976543445675435675435678654567";
    num2.num = "3456789876543567897654356789765435678976534567898765435678976543567897654356789765345678987654356789765435678976543567897653456789876543567897654356789765435678976534567898765435678976543567897654356789765";
    num1 = num1-num2;
    resultTest = "-3456789876543567897654356789759756781322190000355197892111111086811108677813344089910003551975702222197545913542086813540899100003330867889000000012222221868135408669111141976459135530868132222218678135198";

    EXPECT_EQ(num1.num,resultTest);
}

TEST(bigIntTest,mult){
    //test 1
    bigInt num1,num2;
    std::string resultTest;
    num1.num = "123";
    num2.num = "321";
    num1 = num1*num2;
    resultTest = "39483";

    EXPECT_EQ(num1.num,resultTest);

    //test 2
    num1.num = "123333";
    num2.num = "321";
    num1 = num1*num2;
    resultTest = "39589893";

    EXPECT_EQ(num1.num,resultTest);

    //test 3
    num1.num = "321";
    num2.num = "123333";
    num1 = num1*num2;
    resultTest = "39589893";

    EXPECT_EQ(num1.num,resultTest);

    //test 4
    num1.num = "99999";
    num2.num = "1";
    num1 = num1*num2;
    resultTest = "99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 5
    num1.num = "99999";
    num2.num = "-1";
    num1 = num1*num2;
    resultTest = "-99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 6
    num1.num = "-99999";
    num2.num = "1";
    num1 = num1*num2;
    resultTest = "-99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 7
    num1.num = "-1";
    num2.num = "99999";
    num1 = num1*num2;
    resultTest = "-99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 8
    num1.num = "1";
    num2.num = "-99999";
    num1 = num1*num2;
    resultTest = "-99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 9
    num1.num = "99999";
    num2.num = "1";
    num1 = num1*num2;
    resultTest = "99999";

    EXPECT_EQ(num1.num,resultTest);

    //test 10
    num1.num = "-99999";
    num2.num = "-99999";
    num1 = num1*num2;
    resultTest = "9999800001";

    EXPECT_EQ(num1.num,resultTest);

    //test 11
    num1.num = "99999";
    num2.num = "-99999";
    num1 = num1*num2;
    resultTest = "-9999800001";

    EXPECT_EQ(num1.num,resultTest);

    //test 12
    num1.num = "5678897654344567543567543567865456756788976543445675435675435678654567567889765434456754356754356786545675678897654344567543567543567865456756788976543445675435675435678654567";
    num2.num = "3456789876543567897654356789765435678976534567898765435678976543567897654356789765345678987654356789765435678976543567897653456789876543567897654356789765435678976534567898765435678976543567897654356789765";
    num1 = num1*num2;
    resultTest = "19630755921465314959168808259121069380918390476056855431025551735258046087425750868881168347313910727271901347780291107272766599279477856652760392207646300551850603626039970231480183953460521374867397280593944934785668270343617724387836567034714120032498092604915840172526332877997152972702684203050089111226270386596838286553319248082430029136563495384449118618787745596476106755";

    EXPECT_EQ(num1.num,resultTest);

    //test 13
    num1.num = "99999";
    num2.num = "-0";
    num1 = num1*num2;
    resultTest = "0";

    EXPECT_EQ(num1.num,resultTest);

    //test 14
    num1.num = "snow";
    num2.num = "";
    num1 = num1*num2;
    resultTest = "0";

    EXPECT_EQ(num1.num,resultTest);
}