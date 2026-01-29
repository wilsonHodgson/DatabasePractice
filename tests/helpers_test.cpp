#include "../helpers.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Testing Environment Variables") {
    REQUIRE(get_env_var("NOASODIFAJSLEKJFAASDFZX") == "");
    REQUIRE(get_env_var("SHELL") == "/bin/bash");
}