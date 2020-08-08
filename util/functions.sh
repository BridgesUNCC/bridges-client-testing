#!/bin/sh

BASE=../
TIMEOUT=mytimeout

mytimeout() { perl -e 'alarm shift; exec @ARGV; exit 1' "$@"; }
filterexecutableonly() { while read filename; do if [ -x "$filename" ]; then echo "$filename" ;fi ; done }

run_java() {
    local test=$1
    (
	cd ../java/web_tutorial_testing/

	##account information set in env_vars.sh
	${TIMEOUT} 60 java $(basename ${test} .java) 1 null null live
	if [ $? -eq 0 ] ;
	then
	    exit 0; #ok
	else
	    exit 1; #error
	fi
    )
}

#takes a directory and essentially run a binary inside
run_cxx() {
    local test=$1
    (
	cd ../c++/web_tutorial_testing/
	
	${TIMEOUT} 60 ./$(basename ${test} .cpp) 1 null null live
	if [ $? -eq 0 ] ;
	then
	    exit 0; #ok
	else
	    exit 1; #error
	fi
    )
}


#takes a directory and essentially $PYTHON  the python file with main
run_python() {
    local test=$1
    (
	cd ../python/web_tutorial_testing/


	${TIMEOUT} 60 ${PYTHON} ${test} 1 null null live
	if [ $? -eq 0 ] ;
	then
	    exit 0; #ok
	else
	    exit 1; #error
	fi
    )
}



build_java() {
    local test=$1
    (
	#echo $CLASSPATH
	cd ../java/web_tutorial_testing/

	javac $test
	if [ $? -eq 0 ] ;
	then
	    exit 0; #ok
	else
	    exit 1; #error
	fi
    )
}


#takes a directory and essentially make in there.
build_cxx() {
    local test=$1
    (
	cd ../c++/web_tutorial_testing/
	
	make clean
	make $(basename $test .cpp)
	
	if [ $? -eq 0 ] ;
	then
	    exit 0; #ok
	else
	    exit 1; #error
	fi
    )
}


# takes an testname such as "grid.java"
build_java_test() {
    local test=$1

    echo "Compiling test ${test}"
    build_java ${test}
    if [ $? -eq 1 ] ;then
	LOGMSG="could not compile java_answer/ for assignment in ${answerdir}"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi
    
    return 0
}


# takes an testname such as "grid.java"
build_cxx_test() {
    local test=$1

    echo "Compiling test ${test}"
    build_cxx ${test}
    if [ $? -eq 1 ] ;then
	LOGMSG="could not compile c++/ for assignment in ${answerdir}"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi
    
    return 0
}


# takes an assignment id such as "find_assignment_directory 12" and build it
build_cxx_answer() {
    local assignment=$1
    local assdir=$(find_assignment_directory ${assignment})
    local answerdir=${assdir}/c++_answer
    if [ -d ${answerdir} ] ; then
	echo "Compiling c++_answer/ for assignment in ${answerdir}"
	build_cxx_arbitrary ${answerdir}
	if [ $? -eq 1 ] ;then
	    LOGMSG="could not compile c++_answer/ for assignment in ${answerdir}"
	    echo ${LOGMSG}
	    LOG="${LOG}\n${LOGMSG}"
	    return 1
	fi
    else
	LOGMSG="assignment ${assignment} has no c++_answer directory"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi
    return 0
}



run_java_test() {
    local test=$1
    
    run_java ${test}

    if [ $? -eq 1 ] ; then
	LOGMSG="could not run test ${test}"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi


    return 0
}


run_cxx_test() {
    local test=$1

    run_cxx ${test}
    
    if [ $? -eq 1 ] ; then
	LOGMSG="could not run test ${answerdir}"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi
    
    return 0
}



run_python_test() {
    local test=$1
    
    run_python ${test}

    if [ $? -eq 1 ] ; then
	LOGMSG="could not run test ${test}"
	echo ${LOGMSG}
	LOG="${LOG}\n${LOGMSG}"
	return 1
    fi

    return 0
}



