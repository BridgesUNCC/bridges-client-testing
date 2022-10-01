#!/bin/sh

HTMLLOG=python_testing_logs.html
HTMLLOGDIR=python_testing_logs
LANGUAGE=python
LANGUAGEHTMLLOG=${HTMLLOG}

. ./env_vars.sh
. ./functions.sh
. ./html_functions.sh

exit #disabling testing

check_tools

clean_html_log
html_log_header Python

cd ../python/web_tutorial_testing

SRCS=$(grep -l "if __name__ == \"__main__\":" *.py | sort -V )

cd -


export FORCE_BRIDGES_ASSIGNMENT=3000

for i in ${SRCS};
do
    echo ===================================
    echo ===========Assignment ${i}===========
    echo ===================================

    { run_python_test $i ; echo $? > ${HTMLLOGDIR}/${i}-runtest-code ; }  2>&1 | tee -a ${HTMLLOGDIR}/${i}-runtest

    export FORCE_BRIDGES_ASSIGNMENT=$(expr ${FORCE_BRIDGES_ASSIGNMENT} + 1)

done

## build summary

for i in ${SRCS};
do
    run_test_code=$(cat ${HTMLLOGDIR}/${i}-runtest-code)


    html_log_summary_item_header $i ${run_test_code}

    html_log_summary_item $i "Run Test" "runtest"
    
    html_log_summary_item_footer $i
    
done


## build detail HTML log

for i in ${SRCS};
do
    html_log_detail_header $i

    html_log_detail_item $i "Run Test" "runtest"
        
    html_log_detail_footer $i
    
done 


html_log_footer
