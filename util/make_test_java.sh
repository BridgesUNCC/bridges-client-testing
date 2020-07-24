#!/bin/sh

#. ../env_vars.mk


# echo $SRCS

# compile_java() {
#     make $(basename $1 .java).class
# }

# for file in $SRCS;
# do
#     compile_java $file
# done



HTMLLOG=java_testing_logs.html
HTMLLOGDIR=java_testing_logs
LANGUAGE=java
LANGUAGEHTMLLOG=${HTMLLOG}

. ./env_vars.sh
. ./functions.sh
. ./html_functions.sh


check_tools


clean_html_log
html_log_header Java

#clear all binaries
find $BASE -type f -name *\.class | xargs rm

cd ../java/web_tutorial_testing

SRCS=$(grep -l public\ static\ void\ main *.java | sort )

cd -


for i in ${SRCS};
do
    echo ===================================
    echo ===========Test ${i}===========
    echo ===================================


    { build_java_test $i ; echo $? > ${HTMLLOGDIR}/${i}-buildtest-code ; }  2>&1 | tee -a ${HTMLLOGDIR}/${i}-buildtest

    { run_java_test $i ; echo $? > ${HTMLLOGDIR}/${i}-runtest-code ; }  2>&1 | tee -a ${HTMLLOGDIR}/${i}-runtest
    
done

## build summary

for i in ${SRCS};
do
    build_answer_test=$(cat ${HTMLLOGDIR}/${i}-buildtest-code)
    run_answer_test=$(cat ${HTMLLOGDIR}/${i}-runtest-code)


    html_log_summary_item_header $i ${build_answer_test} ${run_answer_test}

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
