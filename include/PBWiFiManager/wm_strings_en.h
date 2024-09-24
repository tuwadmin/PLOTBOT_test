/**
 * wm_strings_en.h
 * engligh strings for
 * WiFiManager, a library for the ESP8266/Arduino platform
 * for configuration of WiFi credentials using a Captive Portal
 *
 * @author Creator tzapu
 * @author tablatronix
 * @version 0.0.0
 * @license MIT
 */

#ifndef _WM_STRINGS_EN_H_
#define _WM_STRINGS_EN_H_


#ifndef WIFI_MANAGER_OVERRIDE_STRINGS
// !!! ABOVE WILL NOT WORK if you define in your sketch, must be build flag, if anyone one knows how to order includes to be able to do this it would be neat.. I have seen it done..

// strings files must include a consts file!
#include "wm_consts_en.h" // include constants, tokens, routes

const char WM_LANGUAGE[] PROGMEM = "en-US"; // i18n lang code

const char HTTP_HEAD_START[]       PROGMEM = "<!DOCTYPE html>"
"<html lang='en'><head>"
"<meta name='format-detection' content='telephone=no'>"
"<meta charset='UTF-8'>"
"<meta  name='viewport' content='width=device-width,initial-scale=1,user-scalable=no'/>"
"<title>{v}</title>";

const char HTTP_SCRIPT[]           PROGMEM = "<script>function c(l){"
"document.getElementById('s').value=l.getAttribute('data-ssid')||l.innerText||l.textContent;"
"p = l.nextElementSibling.classList.contains('l');"
"document.getElementById('p').disabled = !p;"
"if(p)document.getElementById('p').focus();};"
"function f() {var x = document.getElementById('p');x.type==='password'?x.type='text':x.type='password';}"
"</script>"; // @todo add button states, disable on click , show ack , spinner etc

const char HTTP_HEAD_END[]         PROGMEM = "</head><body class='{c}'><div class='wrap'>"; // {c} = _bodyclass
// example of embedded logo, base64 encoded inline, No styling here
const char HTTP_ROOT_MAIN[]        PROGMEM = "<p style='text-align:center'><img width='250' src='data:image/jpeg;base64,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' /> </p><h3 style='text-align:center'>{v}</h3>";
//const char HTTP_ROOT_MAIN[]        PROGMEM = "<h1>{t}</h1><h3>{v}</h3>";

const char * const HTTP_PORTAL_MENU[] PROGMEM = {
"<form action='/wifi'    method='get'><button>Configure WiFi</button></form><br/>\n", // MENU_WIFI
"<form action='/0wifi'   method='get'><button>Configure WiFi (No scan)</button></form><br/>\n", // MENU_WIFINOSCAN
"<form action='/info'    method='get'><button>Info</button></form><br/>\n", // MENU_INFO
"<form action='/param'   method='get'><button>Setup</button></form><br/>\n",//MENU_PARAM
"<form action='/close'   method='get'><button>Close</button></form><br/>\n", // MENU_CLOSE
"<form action='/restart' method='get'><button>Restart</button></form><br/>\n",// MENU_RESTART
"<form action='/exit'    method='get'><button>Exit</button></form><br/>\n",  // MENU_EXIT
"<form action='/erase'   method='get'><button class='D'>Erase</button></form><br/>\n", // MENU_ERASE
"<form action='/update'  method='get'><button>Update</button></form><br/>\n",// MENU_UPDATE
"<hr><br/>" // MENU_SEP
};

// const char HTTP_PORTAL_OPTIONS[]   PROGMEM = strcat(HTTP_PORTAL_MENU[0] , HTTP_PORTAL_MENU[3] , HTTP_PORTAL_MENU[7]);
const char HTTP_PORTAL_OPTIONS[]   PROGMEM = "";
const char HTTP_ITEM_QI[]          PROGMEM = "<div role='img' aria-label='{r}%' title='{r}%' class='q q-{q} {i} {h}'></div>"; // rssi icons
const char HTTP_ITEM_QP[]          PROGMEM = "<div class='q {h}'>{r}%</div>"; // rssi percentage {h} = hidden showperc pref
const char HTTP_ITEM[]             PROGMEM = "<div><a href='#p' onclick='c(this)' data-ssid='{V}'>{v}</a>{qi}{qp}</div>"; // {q} = HTTP_ITEM_QI, {r} = HTTP_ITEM_QP
// const char HTTP_ITEM[]            PROGMEM = "<div><a href='#p' onclick='c(this)'>{v}</a> {R} {r}% {q} {e}</div>"; // test all tokens

const char HTTP_FORM_START[]       PROGMEM = "<form method='POST' action='{v}'>";
const char HTTP_FORM_WIFI[]        PROGMEM = "<label for='s'>SSID</label><input id='s' name='s' maxlength='32' autocorrect='off' autocapitalize='none' placeholder='{v}'><br/><label for='p'>Password</label><input id='p' name='p' maxlength='64' type='password' placeholder='{p}'><input type='checkbox' id='showpass' onclick='f()'> <label for='showpass'>Show Password</label><br/>";
const char HTTP_FORM_WIFI_END[]    PROGMEM = "";
const char HTTP_FORM_STATIC_HEAD[] PROGMEM = "<hr><br/>";
const char HTTP_FORM_END[]         PROGMEM = "<br/><br/><button type='submit'>Save</button></form>";
const char HTTP_FORM_LABEL[]       PROGMEM = "<label for='{i}'>{t}</label>";
const char HTTP_FORM_PARAM_HEAD[]  PROGMEM = "<hr><br/>";
const char HTTP_FORM_PARAM[]       PROGMEM = "<br/><input id='{i}' name='{n}' maxlength='{l}' value='{v}' {c}>\n"; // do not remove newline!

const char HTTP_SCAN_LINK[]        PROGMEM = "<br/><form action='/wifi?refresh=1' method='POST'><button name='refresh' value='1'>Refresh</button></form>";
const char HTTP_SAVED[]            PROGMEM = "<div class='msg'>Saving Credentials<br/>Trying to connect ESP to network.<br />If it fails reconnect to AP to try again</div>";
const char HTTP_PARAMSAVED[]       PROGMEM = "<div class='msg S'>Saved<br/></div>";
const char HTTP_END[]              PROGMEM = "</div></body></html>";
const char HTTP_ERASEBTN[]         PROGMEM = "<br/><form action='/erase' method='get'><button class='D'>Erase WiFi config</button></form>";
const char HTTP_UPDATEBTN[]        PROGMEM = "<br/><form action='/update' method='get'><button>Update</button></form>";
const char HTTP_BACKBTN[]          PROGMEM = "<hr><br/><form action='/' method='get'><button>Back</button></form>";

const char HTTP_STATUS_ON[]        PROGMEM = "<div class='msg S'><strong>Connected</strong> to {v}<br/><em><small>with IP {i}</small></em></div>";
const char HTTP_STATUS_OFF[]       PROGMEM = "<div class='msg {c}'><strong>Not connected</strong> to {v}{r}</div>"; // {c=class} {v=ssid} {r=status_off}
const char HTTP_STATUS_OFFPW[]     PROGMEM = "<br/>Authentication failure"; // STATION_WRONG_PASSWORD,  no eps32
const char HTTP_STATUS_OFFNOAP[]   PROGMEM = "<br/>AP not found";   // WL_NO_SSID_AVAIL
const char HTTP_STATUS_OFFFAIL[]   PROGMEM = "<br/>Could not connect"; // WL_CONNECT_FAILED
const char HTTP_STATUS_NONE[]      PROGMEM = "<div class='msg'>No AP set</div>";
const char HTTP_BR[]               PROGMEM = "<br/>";

const char HTTP_STYLE[]            PROGMEM = "<style>"
".c,body{text-align:center;font-family:verdana}div,input,select{padding:5px;font-size:1em;margin:5px 0;box-sizing:border-box}"
"input,button,select,.msg{border-radius:.3rem;width: 100%}input[type=radio],input[type=checkbox]{width:auto}"
"button,input[type='button'],input[type='submit']{cursor:pointer;border:0;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%}"
"input[type='file']{border:1px solid #1fa3ec}"
".wrap {text-align:left;display:inline-block;min-width:260px;max-width:500px}"
// links
"a{color:#000;font-weight:700;text-decoration:none}a:hover{color:#1fa3ec;text-decoration:underline}"
// quality icons
".q{height:16px;margin:0;padding:0 5px;text-align:right;min-width:38px;float:right}.q.q-0:after{background-position-x:0}.q.q-1:after{background-position-x:-16px}.q.q-2:after{background-position-x:-32px}.q.q-3:after{background-position-x:-48px}.q.q-4:after{background-position-x:-64px}.q.l:before{background-position-x:-80px;padding-right:5px}.ql .q{float:left}.q:after,.q:before{content:'';width:16px;height:16px;display:inline-block;background-repeat:no-repeat;background-position: 16px 0;"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGAAAAAQCAMAAADeZIrLAAAAJFBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADHJj5lAAAAC3RSTlMAIjN3iJmqu8zd7vF8pzcAAABsSURBVHja7Y1BCsAwCASNSVo3/v+/BUEiXnIoXkoX5jAQMxTHzK9cVSnvDxwD8bFx8PhZ9q8FmghXBhqA1faxk92PsxvRc2CCCFdhQCbRkLoAQ3q/wWUBqG35ZxtVzW4Ed6LngPyBU2CobdIDQ5oPWI5nCUwAAAAASUVORK5CYII=');}"
// icons @2x media query (32px rescaled)
"@media (-webkit-min-device-pixel-ratio: 2),(min-resolution: 192dpi){.q:before,.q:after {"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALwAAAAgCAMAAACfM+KhAAAALVBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAOrOgAAAADnRSTlMAESIzRGZ3iJmqu8zd7gKjCLQAAACmSURBVHgB7dDBCoMwEEXRmKlVY3L//3NLhyzqIqSUggy8uxnhCR5Mo8xLt+14aZ7wwgsvvPA/ofv9+44334UXXngvb6XsFhO/VoC2RsSv9J7x8BnYLW+AjT56ud/uePMdb7IP8Bsc/e7h8Cfk912ghsNXWPpDC4hvN+D1560A1QPORyh84VKLjjdvfPFm++i9EWq0348XXnjhhT+4dIbCW+WjZim9AKk4UZMnnCEuAAAAAElFTkSuQmCC');"
"background-size: 95px 16px;}}"
// msg callouts
".msg{padding:20px;margin:20px 0;border:1px solid #eee;border-left-width:5px;border-left-color:#777}.msg h4{margin-top:0;margin-bottom:5px}.msg.P{border-left-color:#1fa3ec}.msg.P h4{color:#1fa3ec}.msg.D{border-left-color:#dc3630}.msg.D h4{color:#dc3630}.msg.S{border-left-color: #5cb85c}.msg.S h4{color: #5cb85c}"
// lists
"dt{font-weight:bold}dd{margin:0;padding:0 0 0.5em 0;min-height:12px}"
"td{vertical-align: top;}"
".h{display:none}"
"button{transition: 0s opacity;transition-delay: 3s;transition-duration: 0s;cursor: pointer}"
"button.D{background-color:#91d4fc}"
"button:active{opacity:50% !important;cursor:wait;transition-delay: 0s}"
// invert
"body.invert,body.invert a,body.invert h1 {background-color:#060606;color:#fff;}"
"body.invert .msg{color:#fff;background-color:#282828;border-top:1px solid #555;border-right:1px solid #555;border-bottom:1px solid #555;}"
"body.invert .q[role=img]{-webkit-filter:invert(1);filter:invert(1);}"
":disabled {opacity: 0.5;}"
"</style>";

#ifndef WM_NOHELP
const char HTTP_HELP[]             PROGMEM =
 "<br/><h3>Available pages</h3><hr>"
 "<table class='table'>"
 "<thead><tr><th>Page</th><th>Function</th></tr></thead><tbody>"
 "<tr><td><a href='/'>/</a></td>"
 "<td>Menu page.</td></tr>"
 "<tr><td><a href='/wifi'>/wifi</a></td>"
 "<td>Show WiFi scan results and enter WiFi configuration.(/0wifi noscan)</td></tr>"
 "<tr><td><a href='/wifisave'>/wifisave</a></td>"
 "<td>Save WiFi configuration information and configure device. Needs variables supplied.</td></tr>"
 "<tr><td><a href='/param'>/param</a></td>"
 "<td>Parameter page</td></tr>"
 "<tr><td><a href='/info'>/info</a></td>"
 "<td>Information page</td></tr>"
 "<tr><td><a href='/u'>/u</a></td>"
 "<td>OTA Update</td></tr>"
 "<tr><td><a href='/close'>/close</a></td>"
 "<td>Close the captiveportal popup, config portal will remain active</td></tr>"
 "<tr><td>/exit</td>"
 "<td>Exit Config portal, config portal will close</td></tr>"
 "<tr><td>/restart</td>"
 "<td>Reboot the device</td></tr>"
 "<tr><td>/erase</td>"
 "<td>Erase WiFi configuration and reboot device. Device will not reconnect to a network until new WiFi configuration data is entered.</td></tr>"
 "</table>"
 "<p/>Github <a href='https://github.com/tzapu/WiFiManager'>https://github.com/tzapu/WiFiManager</a>.";
#else
const char HTTP_HELP[]             PROGMEM = "";
#endif

const char HTTP_UPDATE[] PROGMEM = "Upload new firmware<br/><form method='POST' action='u' enctype='multipart/form-data' onchange=\"(function(el){document.getElementById('uploadbin').style.display = el.value=='' ? 'none' : 'initial';})(this)\"><input type='file' name='update' accept='.bin,application/octet-stream'><button id='uploadbin' type='submit' class='h D'>Update</button></form><small><a href='http://192.168.4.1/update' target='_blank'>* May not function inside captive portal, open in browser http://192.168.4.1</a><small>";
const char HTTP_UPDATE_FAIL[] PROGMEM = "<div class='msg D'><strong>Update failed!</strong><Br/>Reboot device and try again</div>";
const char HTTP_UPDATE_SUCCESS[] PROGMEM = "<div class='msg S'><strong>Update successful.  </strong> <br/> Device rebooting now...</div>";

#ifdef WM_JSTEST
const char HTTP_JS[] PROGMEM =
"<script>function postAjax(url, data, success) {"
"    var params = typeof data == 'string' ? data : Object.keys(data).map("
"            function(k){ return encodeURIComponent(k) + '=' + encodeURIComponent(data[k]) }"
"        ).join('&');"
"    var xhr = window.XMLHttpRequest ? new XMLHttpRequest() : new ActiveXObject(\"Microsoft.XMLHTTP\");"
"    xhr.open('POST', url);"
"    xhr.onreadystatechange = function() {"
"        if (xhr.readyState>3 && xhr.status==200) { success(xhr.responseText); }"
"    };"
"    xhr.setRequestHeader('X-Requested-With', 'XMLHttpRequest');"
"    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');"
"    xhr.send(params);"
"    return xhr;}"
"postAjax('/status', 'p1=1&p2=Hello+World', function(data){ console.log(data); });"
"postAjax('/status', { p1: 1, p2: 'Hello World' }, function(data){ console.log(data); });"
"</script>";
#endif

// Info html
// @todo remove html elements from progmem, repetetive strings
#ifdef ESP32
	const char HTTP_INFO_esphead[]    PROGMEM = "<h3>esp32</h3><hr><dl>";
	const char HTTP_INFO_chiprev[]    PROGMEM = "<dt>Chip rev</dt><dd>{1}</dd>";
  	const char HTTP_INFO_lastreset[]  PROGMEM = "<dt>Last reset reason</dt><dd>CPU0: {1}<br/>CPU1: {2}</dd>";
  	const char HTTP_INFO_aphost[]     PROGMEM = "<dt>Access point hostname</dt><dd>{1}</dd>";
    const char HTTP_INFO_psrsize[]    PROGMEM = "<dt>PSRAM Size</dt><dd>{1} bytes</dd>";
	const char HTTP_INFO_temp[]       PROGMEM = "<dt>Temperature</dt><dd>{1} C&deg; / {2} F&deg;</dd>";
    const char HTTP_INFO_hall[]       PROGMEM = "<dt>Hall</dt><dd>{1}</dd>";
#else
	const char HTTP_INFO_esphead[]    PROGMEM = "<h3>esp8266</h3><hr><dl>";
	const char HTTP_INFO_fchipid[]    PROGMEM = "<dt>Flash chip ID</dt><dd>{1}</dd>";
	const char HTTP_INFO_corever[]    PROGMEM = "<dt>Core version</dt><dd>{1}</dd>";
	const char HTTP_INFO_bootver[]    PROGMEM = "<dt>Boot version</dt><dd>{1}</dd>";
	const char HTTP_INFO_lastreset[]  PROGMEM = "<dt>Last reset reason</dt><dd>{1}</dd>";
	const char HTTP_INFO_flashsize[]  PROGMEM = "<dt>Real flash size</dt><dd>{1} bytes</dd>";
#endif

const char HTTP_INFO_memsmeter[]  PROGMEM = "<br/><progress value='{1}' max='{2}'></progress></dd>";
const char HTTP_INFO_memsketch[]  PROGMEM = "<dt>Memory - Sketch size</dt><dd>Used / Total bytes<br/>{1} / {2}";
const char HTTP_INFO_freeheap[]   PROGMEM = "<dt>Memory - Free heap</dt><dd>{1} bytes available</dd>";
const char HTTP_INFO_wifihead[]   PROGMEM = "<br/><h3>WiFi</h3><hr>";
const char HTTP_INFO_uptime[]     PROGMEM = "<dt>Uptime</dt><dd>{1} mins {2} secs</dd>";
const char HTTP_INFO_chipid[]     PROGMEM = "<dt>Chip ID</dt><dd>{1}</dd>";
const char HTTP_INFO_idesize[]    PROGMEM = "<dt>Flash size</dt><dd>{1} bytes</dd>";
const char HTTP_INFO_sdkver[]     PROGMEM = "<dt>SDK version</dt><dd>{1}</dd>";
const char HTTP_INFO_cpufreq[]    PROGMEM = "<dt>CPU frequency</dt><dd>{1}MHz</dd>";
const char HTTP_INFO_apip[]       PROGMEM = "<dt>Access point IP</dt><dd>{1}</dd>";
const char HTTP_INFO_apmac[]      PROGMEM = "<dt>Access point MAC</dt><dd>{1}</dd>";
const char HTTP_INFO_apssid[]     PROGMEM = "<dt>Access point SSID</dt><dd>{1}</dd>";
const char HTTP_INFO_apbssid[]    PROGMEM = "<dt>BSSID</dt><dd>{1}</dd>";
const char HTTP_INFO_stassid[]    PROGMEM = "<dt>Station SSID</dt><dd>{1}</dd>";
const char HTTP_INFO_staip[]      PROGMEM = "<dt>Station IP</dt><dd>{1}</dd>";
const char HTTP_INFO_stagw[]      PROGMEM = "<dt>Station gateway</dt><dd>{1}</dd>";
const char HTTP_INFO_stasub[]     PROGMEM = "<dt>Station subnet</dt><dd>{1}</dd>";
const char HTTP_INFO_dnss[]       PROGMEM = "<dt>DNS Server</dt><dd>{1}</dd>";
const char HTTP_INFO_host[]       PROGMEM = "<dt>Hostname</dt><dd>{1}</dd>";
const char HTTP_INFO_stamac[]     PROGMEM = "<dt>Station MAC</dt><dd>{1}</dd>";
const char HTTP_INFO_conx[]       PROGMEM = "<dt>Connected</dt><dd>{1}</dd>";
const char HTTP_INFO_autoconx[]   PROGMEM = "<dt>Autoconnect</dt><dd>{1}</dd>";

const char HTTP_INFO_aboutver[]     PROGMEM = "<dt>WiFiManager</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutarduino[] PROGMEM = "<dt>Arduino</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutsdk[]     PROGMEM = "<dt>ESP-SDK/IDF</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutdate[]    PROGMEM = "<dt>Build date</dt><dd>{1}</dd>";

const char S_brand[]              PROGMEM = "WiFiManager";
const char S_debugPrefix[]        PROGMEM = "*wm:";
const char S_y[]                  PROGMEM = "Yes";
const char S_n[]                  PROGMEM = "No";
const char S_enable[]             PROGMEM = "Enabled";
const char S_disable[]            PROGMEM = "Disabled";
const char S_GET[]                PROGMEM = "GET";
const char S_POST[]               PROGMEM = "POST";
const char S_NA[]                 PROGMEM = "Unknown";
const char S_passph[]             PROGMEM = "********";
const char S_titlewifisaved[]     PROGMEM = "Credentials saved";
const char S_titlewifisettings[]  PROGMEM = "Settings saved";
const char S_titlewifi[]          PROGMEM = "Config ESP";
const char S_titleinfo[]          PROGMEM = "Info";
const char S_titleparam[]         PROGMEM = "Setup";
const char S_titleparamsaved[]    PROGMEM = "Setup saved";
const char S_titleexit[]          PROGMEM = "Exit";
const char S_titlereset[]         PROGMEM = "Reset";
const char S_titleerase[]         PROGMEM = "Erase";
const char S_titleclose[]         PROGMEM = "Close";
const char S_options[]            PROGMEM = "options";
const char S_nonetworks[]         PROGMEM = "No networks found. Refresh to scan again.";
const char S_staticip[]           PROGMEM = "Static IP";
const char S_staticgw[]           PROGMEM = "Static gateway";
const char S_staticdns[]          PROGMEM = "Static DNS";
const char S_subnet[]             PROGMEM = "Subnet";
const char S_exiting[]            PROGMEM = "Exiting";
const char S_resetting[]          PROGMEM = "Module will reset in a few seconds.";
const char S_closing[]            PROGMEM = "You can close the page, portal will continue to run";
const char S_error[]              PROGMEM = "An error occured";
const char S_notfound[]           PROGMEM = "File not found\n\n";
const char S_uri[]                PROGMEM = "URI: ";
const char S_method[]             PROGMEM = "\nMethod: ";
const char S_args[]               PROGMEM = "\nArguments: ";
const char S_parampre[]           PROGMEM = "param_";

// debug strings
const char D_HR[]                 PROGMEM = "--------------------";


// softap ssid default prefix
#ifdef ESP8266
    const char S_ssidpre[]        PROGMEM = "ESP";
#elif defined(ESP32)
    const char S_ssidpre[]        PROGMEM = "ESP32";
#else
    const char S_ssidpre[]        PROGMEM = "WM";
#endif

// END WIFI_MANAGER_OVERRIDE_STRINGS
#endif

#endif
