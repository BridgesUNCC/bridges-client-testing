#!/bin/sh

HTMLLOG=cxx_testing_logs.html
HTMLLOGDIR=cxx_testing_logs
LANGUAGE=cxx
LANGUAGEHTMLLOG=${HTMLLOG}

. ./env_vars.sh
. ./functions.sh
. ./html_functions.sh

check_tools


clean_html_log
html_log_header C++


#clear all binaries
#find $BASE -type f | filterexecutableonly | xargs rm

cd ../c++/web_tutorial_testing

SRCS=$(ls *.cpp | sort)

cd -


export FORCE_BRIDGES_ASSIGNMENT=1000


for i in ${SRCS};
do
    echo ===================================
    echo ===========Test ${i}============
    echo ===================================
    
    { build_cxx_test $i ; echo $? > ${HTMLLOGDIR}/${i}-buildtest-code ; }  2>&1 | tee -a ${HTMLLOGDIR}/${i}-buildtest
    
    { run_cxx_test $i ; echo $? > ${HTMLLOGDIR}/${i}-runtest-code ; }  2>&1 | tee -a ${HTMLLOGDIR}/${i}-runtest

    export FORCE_BRIDGES_ASSIGNMENT=$(expr ${FORCE_BRIDGES_ASSIGNMENT} + 1)

done

## build summary

for i in ${SRCS};
do


    
    build_test_code=$(cat ${HTMLLOGDIR}/${i}-buildtest-code)
    run_test_code=$(cat ${HTMLLOGDIR}/${i}-runtest-code)


    html_log_summary_item_header $i ${build_test_code} ${run_test_code}

    html_log_summary_item $i "Build Test" "buildtest"
    html_log_summary_item $i "Run Test" "runtest"
    
    html_log_summary_item_footer $i
    
done


## build detail HTML log

for i in ${SRCS};
do
    html_log_detail_header $i

    html_log_detail_item $i "Build Test" "buildtest"
    html_log_detail_item $i "Run Test" "runtest"
        
    html_log_detail_footer $i
    
done 


html_log_footer
