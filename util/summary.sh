#!/bin/sh

HTMLLOG=testing_summary.html

. ./env_vars.sh
. ./functions.sh
. ./html_functions.sh

BEG=0
END=34

if [ $# -ge 1 ] ; then
    BEG=$1
    END=$1
fi

if [ $# -ge 2 ] ; then
    END=$2
fi

check_tools

rm ${HTMLLOG}

timeis=$(date)


cat >>${HTMLLOG} <<EOF
<html>
<head>
	<style>
.javalogs, .cxxlogs, .pythonlogs{
float: left;
width: 30%;
margin-left: 1%;
margin-right: 1%;
}
.failure, .success {
min-height: 8em;
}

.failure {
background-color: orangered;
}
.success {
background-color: springgreen;
}

</style>
</head>
<body>
<p>Run at ${timeis}</p> 

EOF



#Java
LANGUAGEHTMLLOG=java_testing_logs.html
HTMLLOGDIR=java_testing_logs
LANGUAGE=java

cd ../java/web_tutorial_testing

JAVASRCS=$(grep -l public\ static\ void\ main *.java | sort -V )

cd -

cat >>${HTMLLOG} <<EOF
<div class="javalogs">
<h2>Java Logs</h2>
EOF


## build summary

for i in ${JAVASRCS};
do
    build_test_code=$(cat ${HTMLLOGDIR}/${i}-buildtest-code)
    run_test_code=$(cat ${HTMLLOGDIR}/${i}-runtest-code)


    html_log_summary_item_header $i ${build_test_code} ${run_test_code}

    html_log_summary_item $i "Build Test" "buildtest"
    html_log_summary_item $i "Run Test" "runtest"
    
    html_log_summary_item_footer $i
    
done

cat >>${HTMLLOG} <<EOF
</div>
EOF


#C++
LANGUAGEHTMLLOG=cxx_testing_logs.html
HTMLLOGDIR=cxx_testing_logs
LANGUAGE=cxx

cd ../c++/web_tutorial_testing

CXXSRCS=$(ls *.cpp | sort -V )

cd -

cat >>${HTMLLOG} <<EOF
<div class="cxxlogs">
<h2>C++ Logs</h2>
EOF

## build summary

for i in ${CXXSRCS};
do
    build_test_code=$(cat ${HTMLLOGDIR}/${i}-buildtest-code)
    run_test_code=$(cat ${HTMLLOGDIR}/${i}-runtest-code)


    html_log_summary_item_header $i  ${build_test_code} ${run_test_code}

    html_log_summary_item $i "Build Test" "buildtest"
    html_log_summary_item $i "Run Test" "runtest"
    
    html_log_summary_item_footer $i
    
done

cat >>${HTMLLOG} <<EOF
</div>
EOF


#python

LANGUAGEHTMLLOG=python_testing_logs.html
HTMLLOGDIR=python_testing_logs
LANGUAGE=python

cd ../python/web_tutorial_testing


S1=$(grep -l "if __name__ == \"__main__\":" *.py )
S2=$(grep -l "if __name__ == '__main__':" *.py)

PYTHONSRCS=$(echo "$S1 $S2"  | sort -V )

cd -

## build summary
cat >>${HTMLLOG} <<EOF
<div class="pythonlogs">
<h2>Python Logs</h2>
EOF


for i in ${PYTHONSRCS};
do
    run_test_code=$(cat ${HTMLLOGDIR}/${i}-runtest-code)

    html_log_summary_item_header $i ${run_test_code}

    html_log_summary_item $i "Run Test" "runtest"
    
    html_log_summary_item_footer $i
    
done
cat >>${HTMLLOG} <<EOF
</div>
EOF

cat >>${HTMLLOG} <<EOF
</body>
</html>
EOF
