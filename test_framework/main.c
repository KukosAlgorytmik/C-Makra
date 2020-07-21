#include <stdio.h>
#include <test_framework.h>
#include <generic_fmt.h>
#include <math.h>

void tc_start(void);
void tc_clean(void);

void tc_start(void)
{
    printf("MOJA F DO INITU\n");
}

void tc_clean(void)
{
    printf("MOJA F DO SPRZATANIA\n");;
}

tc_ret_t f(void);
tc_ret_t g(int a);
tc_ret_t h(void);

tc_ret_t f(void)
{
    T_EXPECT(0 < 1);
    T_EXPECT_EQ(0ul, 1ul);
    T_EXPECT_NEQ((short)1 , (short)1);
    T_EXPECT_GT((char)'A', (char)'Z');
    /* T_ASSERT(0 == 1); */
    T_EXPECT_GEQ(2.78f, 3.14f);
    T_EXPECT_LEQ(100.01, sqrt(90.001));
    T_EXPECT_LT((size_t)1, (size_t)0);
    T_EXPECT(0 == 1);
    T_ASSERT(0 == 1);
}

tc_ret_t g(int a)
{
    T_EXPECT(a > 0);
    T_EXPECT_GT(a, 10);
    T_ASSERT_EQ(a, 11);
}

tc_ret_t h(void)
{
    for (;;);
}

int main(void)
{
    TEST_SUITE_INIT("Moje testy");
    TEST_CASE_RUN(f());
    TEST_CASE_RUN(g(11));
    /* TEST_CASE_RUN(h()); */
    TEST_SUITE_SUMMARY();
    int result = TEST_SUITE_GET_RESULT();

    TEST_SUITE_INIT_WITH_FUNC("Kolejna porcja testow", tc_start, tc_clean);
    TEST_CASE_RUN(g(11));
    TEST_CASE_RUN(g(11));
    TEST_SUITE_SUMMARY();

    return result + TEST_SUITE_GET_RESULT();
}