#!/bin/bash

. test/env.sh

TEST_TIMEOUT=20000000
TEST_BIN=test/test_os/asp/ttsp/obj/sil_test/asp

util_set_cmdname $0
util_do_test 
util_do_log_check