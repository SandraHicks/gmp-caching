/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   simpletest.c
 * Author: sandra
 *
 * Created on April 19, 2017, 10:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/*
 * Simple C Test Suite
 */

void test1() {
    printf("simpletest test 1\n");
}

void test2() {
    printf("simpletest test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (simpletest) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% simpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (simpletest)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (simpletest) \n");

    printf("%%TEST_STARTED%% test2 (simpletest)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (simpletest) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
