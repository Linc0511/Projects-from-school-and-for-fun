#include "Floating_Point.h"
#include <cassert>
#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>

// Simple testing framework to track passes and failures
int tests_passed = 0;
int tests_failed = 0;

// Helper function to check test results for basic types
template<typename T, typename U>
void check(const std::string& test_name, T got, U expected) {
    if (got == expected) {
        tests_passed++;
    } else {
        std::cout << "[ FAIL ] " << test_name << "\n"
                  << "         Expected: " << expected << "\n"
                  << "         Got:      " << got << std::endl;
        tests_failed++;
    }
}

// Specialized check function for FP objects using string representation
void check_fp(const std::string& test_name, const FP& got, const std::string& expected_str) {
    if (got.to_string() == expected_str) {
        tests_passed++;
    } else {
        std::cout << "[ FAIL ] " << test_name << "\n"
                  << "         Expected: " << expected_str << "\n"
                  << "         Got:      " << got.to_string() << std::endl;
        tests_failed++;
    }
}

// Helper to check if two FP values are equal
void check_fp_equal(const std::string& test_name, const FP& a, const FP& b) {
    if (a.to_string() == b.to_string()) {
        tests_passed++;
    } else {
        std::cout << "[ FAIL ] " << test_name << "\n"
                  << "         Expected: " << b.to_string() << "\n"
                  << "         Got:      " << a.to_string() << std::endl;
        tests_failed++;
    }
}

// Test Suite 1: The original failing case from the prompt
void run_original_failing_case() {
    std::cout << "--- Running Original Failing Case ---\n";
    FP a(6, 14, "+1.b+8191");
    FP b(6, 14, "+1.000001b+8191");
    FP c(6, 14, "+1.b+8190");
    FP d(6, 14, "+1.b+8192");

    check("a.ulp_dist(a)", a.ulp_dist(a), (uint64_t)0);
    check("a.ulp_dist(b) [adjacent significand]", a.ulp_dist(b), (uint64_t)1);
    check("a.ulp_dist(c) [one exponent down]", a.ulp_dist(c), (uint64_t)64);
    check("a.ulp_dist(d) [one exponent up]", a.ulp_dist(d), (uint64_t)64);
    std::cout << "Original case tests complete.\n\n";
}

// Test Suite 2: Basic Construction Tests
void run_construction_tests() {
    std::cout << "--- Running Construction Tests ---\n";
    const int sig_bits = 52;
    const int exp_bits = 11;

    // Test various constructors
    FP zero_int(sig_bits, exp_bits, 0);
    check_fp("Constructor with int 0", zero_int, "+0");

    FP one_int(sig_bits, exp_bits, 1);
    check_fp("Constructor with int 1", one_int, "+1.b+0");

    FP neg_one_int(sig_bits, exp_bits, -1);
    check_fp("Constructor with int -1", neg_one_int, "-1.b+0");

    FP zero_double(sig_bits, exp_bits, 0.0);
    check_fp("Constructor with double 0.0", zero_double, "+0");

    FP half_double(sig_bits, exp_bits, 0.5);
    check_fp("Constructor with double 0.5", half_double, "+1.b-1");

    FP two_double(sig_bits, exp_bits, 2.0);
    check_fp("Constructor with double 2.0", two_double, "+1.b+1");

    // Test string constructors
    FP zero_str(sig_bits, exp_bits, "+0");
    check_fp("Constructor with string +0", zero_str, "+0");

    FP neg_zero_str(sig_bits, exp_bits, "-0");
    check_fp("Constructor with string -0", neg_zero_str, "-0");

    FP inf_str(sig_bits, exp_bits, "+INF");
    check_fp("Constructor with string +INF", inf_str, "+INF");

    FP neg_inf_str(sig_bits, exp_bits, "-INF");
    check_fp("Constructor with string -INF", neg_inf_str, "-INF");

    // Test NaN constructor
    FP nan_default(sig_bits, exp_bits);
    check_fp("Default NaN constructor", nan_default, "+NAN");

    std::cout << "Construction tests complete.\n\n";
}

// Test Suite 3: Comprehensive ULP Distance Tests
void run_ulp_distance_tests() {
    std::cout << "--- Running Comprehensive ULP Distance Tests ---\n";
    const int sig_bits = 52;
    const int exp_bits = 11;

    FP zero(sig_bits, exp_bits, 0);
    FP neg_zero(sig_bits, exp_bits, "-0");
    FP one(sig_bits, exp_bits, 1);
    FP two(sig_bits, exp_bits, 2);
    FP neg_one(sig_bits, exp_bits, -1);

    // Smallest positive normal number
    FP min_normal(sig_bits, exp_bits, "+1.b-1022");
    // Largest subnormal number
    FP max_subnormal(sig_bits, exp_bits, "+0.1111111111111111111111111111111111111111111111111111b-1022");
    // Smallest positive subnormal number
    FP min_subnormal(sig_bits, exp_bits, "+0.0000000000000000000000000000000000000000000000000001b-1022");

    FP p_inf(sig_bits, exp_bits, "+INF");
    FP n_inf(sig_bits, exp_bits, "-INF");
    FP nan(sig_bits, exp_bits);

    // Basic distances
    check("ulp_dist(zero, one)", zero.ulp_dist(one), one.ulp_dist(zero));
    check("ulp_dist(one, two)", one.ulp_dist(two), (1ULL << 52));
    
    // Zero distances
    check("ulp_dist(zero, zero)", zero.ulp_dist(zero), (uint64_t)0);
    check("ulp_dist(zero, neg_zero)", zero.ulp_dist(neg_zero), (uint64_t)0);

    // Subnormal distances
    check("ulp_dist(zero, min_subnormal)", zero.ulp_dist(min_subnormal), (uint64_t)1);
    check("ulp_dist(max_subnormal, min_normal)", max_subnormal.ulp_dist(min_normal), (uint64_t)1);
    
    // Cross-zero distances
    uint64_t one_to_zero = one.ulp_dist(zero);
    uint64_t neg_one_to_zero = neg_one.ulp_dist(zero);
    check("ulp_dist(one, neg_one)", one.ulp_dist(neg_one), one_to_zero + neg_one_to_zero);

    // Infinity and NaN
    FP max_normal(sig_bits, exp_bits, "+1.1111111111111111111111111111111111111111111111111111b+1023");
    check("ulp_dist(max_normal, p_inf)", max_normal.ulp_dist(p_inf), (uint64_t)1);
    check("ulp_dist(one, nan)", one.ulp_dist(nan), UINT64_MAX);
    check("ulp_dist(nan, p_inf)", nan.ulp_dist(p_inf), UINT64_MAX);
    
    // Symmetry tests
    check("ulp_dist symmetry: one to two", one.ulp_dist(two), two.ulp_dist(one));
    check("ulp_dist symmetry: min_normal to max_subnormal", 
          min_normal.ulp_dist(max_subnormal), max_subnormal.ulp_dist(min_normal));

    std::cout << "ULP distance tests complete.\n\n";
}

// Test Suite 4: Addition and Rounding Tests
void run_addition_rounding_tests() {
    std::cout << "--- Running Addition and Rounding Tests ---\n";
    const int sig_bits = 4;
    const int exp_bits = 5;

    FP one(sig_bits, exp_bits, "+1.b+0");
    FP half_ulp(sig_bits, exp_bits, "+1.b-5");
    FP one_ulp(sig_bits, exp_bits, "+1.b-4");

    // Test NEAR_EVEN (round to nearest, ties to even)
    FP res_ne = one;
    res_ne.add(half_ulp, FP::NEAR_EVEN);
    check_fp("1.0 + 0.5 ULP (NEAR_EVEN)", res_ne, "+1.b+0");

    // Test NEAR_AWAY (round to nearest, ties away from zero)
    FP res_na = one;
    res_na.add(half_ulp, FP::NEAR_AWAY);
    check_fp("1.0 + 0.5 ULP (NEAR_AWAY)", res_na, "+1.0001b+0");

    // Test ZERO (truncate)
    FP res_z = one;
    res_z.add(one_ulp, FP::ZERO);
    check_fp("1.0 + 1 ULP (ZERO)", res_z, "+1.b+0");

    // Test UP (toward +infinity)
    FP res_u = one;
    res_u.add(half_ulp, FP::UP);
    check_fp("1.0 + 0.5 ULP (UP)", res_u, "+1.0001b+0");

    // Test DOWN (toward -infinity)
    FP res_d = one;
    res_d.add(half_ulp, FP::DOWN);
    check_fp("1.0 + 0.5 ULP (DOWN)", res_d, "+1.b+0");

    // Exact cancellation
    FP x(sig_bits, exp_bits, "+1.101b+5");
    FP y(sig_bits, exp_bits, "-1.101b+5");
    x.add(y);
    check_fp("Exact Cancellation x+(-x)", x, "+0");

    // Large number addition
    FP large1(sig_bits, exp_bits, "+1.111b+10");
    FP small1(sig_bits, exp_bits, "+1.b+0");
    large1.add(small1);
    check_fp("Large + small number", large1, "+1.111b+10");

    std::cout << "Addition and rounding tests complete.\n\n";
}

// Test Suite 5: Special Values (NaN, Infinity)
void run_special_value_tests() {
    std::cout << "--- Running Special Value Tests ---\n";
    const int sig_bits = 52;
    const int exp_bits = 11;

    FP p_inf(sig_bits, exp_bits, "+INF");
    FP n_inf(sig_bits, exp_bits, "-INF");
    FP nan(sig_bits, exp_bits);
    FP one(sig_bits, exp_bits, 1);
    FP zero(sig_bits, exp_bits, 0);
    
    // Infinity arithmetic
    FP res1 = p_inf;
    res1.add(one);
    check_fp("inf + 1", res1, "+INF");

    res1 = p_inf;
    res1.add(p_inf);
    check_fp("inf + inf", res1, "+INF");

    res1 = p_inf;
    res1.add(n_inf);
    check_fp("inf + (-inf)", res1, "+NAN");

    res1 = n_inf;
    res1.add(n_inf);
    check_fp("(-inf) + (-inf)", res1, "-INF");

    // NaN propagation
    FP res2 = one;
    res2.add(nan);
    check_fp("1 + NaN", res2, "+NAN");
    
    res2 = nan;
    res2.add(p_inf);
    check_fp("NaN + inf", res2, "+NAN");

    res2 = zero;
    res2.add(nan);
    check_fp("0 + NaN", res2, "+NAN");
    
    std::cout << "Special value tests complete.\n\n";
}

// Test Suite 6: Edge Cases and Overflow/Underflow
void run_edge_case_tests() {
    std::cout << "--- Running Edge Case Tests ---\n";
    const int sig_bits = 4;
    const int exp_bits = 3;

    // Test overflow to infinity
    FP large(sig_bits, exp_bits, "+1.111b+3");  // Near maximum
    FP small_pos(sig_bits, exp_bits, "+1.b+0");
    large.add(small_pos);
    check_fp("Overflow to +INF", large, "+INF");

    // Test underflow to zero
    FP tiny(sig_bits, exp_bits, "+1.b-4");  // Very small
    FP neg_tiny(sig_bits, exp_bits, "-1.b-4");
    tiny.add(neg_tiny);
    check_fp("Underflow to zero", tiny, "+0");

    // Test subnormal arithmetic
    FP subnormal1(sig_bits, exp_bits, "+0.001b-4");
    FP subnormal2(sig_bits, exp_bits, "+0.001b-4");
    subnormal1.add(subnormal2);
    check_fp("Subnormal + subnormal", subnormal1, "+0.01b-4");

    std::cout << "Edge case tests complete.\n\n";
}

// Test Suite 7: Different Precision Tests
void run_precision_tests() {
    std::cout << "--- Running Different Precision Tests ---\n";
    
    // Test with half precision (IEEE 754 binary16)
    const int half_sig = 10;
    const int half_exp = 5;
    
    FP half_one(half_sig, half_exp, "+1.b+0");
    FP half_two(half_sig, half_exp, "+1.b+1");
    check_fp("Half precision: 1.0", half_one, "+1.b+0");
    check_fp("Half precision: 2.0", half_two, "+1.b+1");
    
    half_one.add(half_two);
    check_fp("Half precision: 1.0 + 2.0", half_one, "+1.1b+1");

    // Test with single precision (IEEE 754 binary32)
    const int single_sig = 23;
    const int single_exp = 8;
    
    FP single_pi(single_sig, single_exp, 3.14159265359);
    FP single_e(single_sig, single_exp, 2.71828182846);
    single_pi.add(single_e);
    
    // Test very small precision
    const int tiny_sig = 2;
    const int tiny_exp = 2;
    
    FP tiny_one(tiny_sig, tiny_exp, "+1.b+0");
    FP tiny_quarter(tiny_sig, tiny_exp, "+1.b-2");
    tiny_one.add(tiny_quarter);
    check_fp("Tiny precision: 1.0 + 0.25", tiny_one, "+1.01b+0");

    std::cout << "Precision tests complete.\n\n";
}

// Test Suite 8: Stress Tests
void run_stress_tests() {
    std::cout << "--- Running Stress Tests ---\n";
    const int sig_bits = 52;
    const int exp_bits = 11;

    // Test many small additions
    FP accumulator(sig_bits, exp_bits, 0.0);
    FP small_val(sig_bits, exp_bits, 1e-10);
    
    for (int i = 0; i < 1000; i++) {
        accumulator.add(small_val);
    }
    
    // Check if accumulator is reasonable (should be around 1e-7)
    // We can't check exact equality due to rounding
    
    // Test alternating additions
    FP alternating(sig_bits, exp_bits, 0.0);
    FP pos_val(sig_bits, exp_bits, 1.0);
    FP neg_val(sig_bits, exp_bits, -1.0);
    
    for (int i = 0; i < 100; i++) {
        alternating.add(pos_val);
        alternating.add(neg_val);
    }
    check_fp("Alternating +1/-1 additions", alternating, "+0");

    std::cout << "Stress tests complete.\n\n";
}

int main() {
    std::cout << "=======================================\n";
    std::cout << "     STARTING FP CLASS TEST SUITE      \n";
    std::cout << "=======================================\n\n";

    run_original_failing_case();
    run_construction_tests();
    run_ulp_distance_tests();
    run_addition_rounding_tests();
    run_special_value_tests();
    run_edge_case_tests();
    run_precision_tests();
    run_stress_tests();

    std::cout << "---------------------------------------\n";
    std::cout << "                 SUMMARY               \n";
    std::cout << "---------------------------------------\n";
    std::cout << "Tests Passed: " << tests_passed << "\n";
    std::cout << "Tests Failed: " << tests_failed << "\n";
    std::cout << "=======================================\n\n";

    if (tests_failed > 0) {
        std::cout << "Some tests failed.\n";
        return 1;
    } else {
        std::cout << "All tests passed!\n";
        return 0;
    }
}