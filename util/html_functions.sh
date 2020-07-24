#!/bin/sh

code_to_string() {
    if [ "$1" = "0" ] ; then
	echo "success"
    else
	echo "error"
    fi
}

clean_html_log() {
    rm ${HTMLLOG}
    rm -rf ${HTMLLOGDIR}
    mkdir ${HTMLLOGDIR}
}

html_log_header() {
    local language=$1
    timeis=$(date)
    cat >> ${HTMLLOG} <<EOF
    <html>
    <head>
<style>
.failure {
background-color: orangered;
}
.success {
background-color: springgreen;
}
</style>
    </head>
    <body>
	<h1>Testing logs for ${language}</h1>
	<p>Running at ${timeis}</p>
EOF
}

html_log_footer() {

    cat >> ${HTMLLOG} <<EOF
  </body>
EOF

}

html_log_detail_header() {
    local assignment=$1
    cat >> ${HTMLLOG} <<EOF
    <div id="${LANGUAGE}log${assignment}" class="logdetails">
      <h2>Test ${assignment} full log</h2>
    
EOF
}

html_log_detail_item() {
    local assignment=$1
    local prettystr=$2
    local itemid=$3

    local code=$(cat ${HTMLLOGDIR}/${assignment}-${itemid}-code)

    local class="success"
    if [ "${code}" = "1" ] ;
    then
	class="failure"
    fi

    echo \<div class=\"${class}\"\> >> ${HTMLLOG}
    {
	echo \#\#\# \<span id=\"${LANGUAGE}log${assignment}-${itemid}\"\>${prettystr} for test ${assignment}\</span\>

	echo \`\`\`
	
	cat ${HTMLLOGDIR}/${assignment}-${itemid}
	echo \`\`\`
	
    } | ${MARKDOWN} >> ${HTMLLOG}

    echo \</div\> >> ${HTMLLOG}
    
}


html_log_detail_footer() {
    local assignment=$1
    cat >> ${HTMLLOG} <<EOF
    
    </div>
EOF
}

## takes assingment number followd by all error codes
html_log_summary_item_header() {
    local assignment=$1

    shift
    local class="success"
    
    while [ $# -ge 1  ]
    do
	local code=$1
	if [ "${code}" = "1" ] ;
	then
	    class="failure"
	fi
	shift
    done
    
    
    cat >>${HTMLLOG} <<EOF
  <div id="summary${i}" class="${class}">
    <h2><a href="${LANGUAGEHTMLLOG}#${LANGUAGE}log${i}">Test ${i}</a> </h2>
    <p>
      <ul>
EOF
}

html_log_summary_item() {
    local assignment=$1
    local prettystr=$2
    local itemid=$3

    local code=$(cat ${HTMLLOGDIR}/${assignment}-${itemid}-code)
    

    local statusstring=$(code_to_string ${code})
    cat >> ${HTMLLOG} <<EOF
        <li> ${prettystr} : <a href="${LANGUAGEHTMLLOG}#${LANGUAGE}log${assignment}-${itemid}">${statusstring}</a></li>
EOF
}

html_log_summary_item_footer() {
        local assignment=$1
  cat >>${HTMLLOG} <<EOF
      </ul>
    </p>
  </div>
EOF
}


check_tools() {
    if [ "" = "${MARKDOWN}" ];
    then
	echo "variable MARKDOWN should be defined in ./env_vars.sh"
	exit 1
    fi
}
