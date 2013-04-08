



  



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
  <head>
    <script type="text/javascript">
//<![CDATA[
document.domain = 'assembla.com';
//]]>
</script>
    <title>OBC/trunk/Firmware/cc1020/cc1020.h | Source/SVN | Assembla</title>
    <link href="http://assets1.assembla.com/favicon.ico?1306321271" type="image/x-icon" rel="shortcut icon" />
    <link href="http://assets0.assembla.com/favicon.ico?1306321271" type="image/x-icon" rel="icon" />
    <meta name="csrf-param" content="authenticity_token"/>
<meta name="csrf-token" content="T/RDNnV5MgB6KmIe0UcZSlGFBQhbF8cru30lmZBCvT4="/>
    <link href="http://assets0.assembla.com/stylesheets/base_app_and_alerts_packaged.css?1311939604" media="all" rel="stylesheet" type="text/css" />
    
    
    <link href="http://assets1.assembla.com/stylesheets/code_packaged.css?1311939604" media="all" rel="stylesheet" type="text/css" />  

      <style type="text/css" media="all" rel="stylesheet" id="branded_css">
        
        
      </style>
    
    <link href="http://assets0.assembla.com/stylesheets/print.css?1311939273" media="print" rel="stylesheet" type="text/css" />

    <!--[if IE 7]>
        <link rel="stylesheet" type="text/css" href="/stylesheets/ie7.css">
    <![endif]-->

    <!--[if lte IE 8]>
        <link rel="stylesheet" type="text/css" href="/stylesheets/ie8.css">
    <![endif]-->

    <script src="http://assets0.assembla.com/javascripts/base_packaged.js?1311939592" type="text/javascript"></script>
    
    
    
    <script src="http://assets1.assembla.com/javascripts/code_packaged.js?1311939594" type="text/javascript"></script>  <script type="text/javascript">
//<![CDATA[
I18n.locale = 'en'
//]]>
</script>
  


      
  
  


    <!-- prevents swf file caching -->
    <meta http-equiv="PRAGMA" content="NO-CACHE" />
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    

  </head>
  <body>
    <div class="b-wrapper">
      <a name="pagetop"></a>
        <script type="text/javascript">
    var _gaq = _gaq || [];
    _gaq.push(['_setAccount', 'UA-2641193-1']);
    _gaq.push(['_setCustomVar',1,'Logged','true',1]);
    
    _gaq.push(['_trackPageview']);

    (function() {
      var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
      ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
      (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
    })();
  </script>


      <div class="hidden">
        <a href="#content">Skip to contents</a>
      </div>

      

    <div id="header-w">

  <div id="header" class="_">

    <div id="header-links">
      <div id="user-box">
        avnish kumar <span>|</span>
        <a href="/start"><strong>My Start Page</strong></a>
      <span>|</span>
  <a href="/user/logout">Logout</a>


      </div>
      <div>
      <span id="space-role">Free/Public Space <span>|</span> <a href="/spaces/watch/pratham" class="watch" data-method="post" rel="nofollow" title="Add this space to your spaces list">Watch</a> <a href="/code/pratham/subversion/forks/new" class="fork" title="Make a new space to clone this repository">Fork</a></span>
      </div>
    </div>

    <div id="logo">
        <a href="/">
          <img src="/images/assembla-logo-small.png" alt="Go to Assembla" title="Go to Assembla" />
        </a>
    </div>

        

      <h1 class="header-w clear-float">
        <span>Code Repository</span>
      </h1>

    <div class="cut">&nbsp;</div>

  </div><!-- /header -->
</div><!-- /header-w -->

    
      <div id="main-menu-w">
        <ul class='clear-float' id='main-menu'><li class=""><a href="/spaces/pratham/wiki">Wiki</a></li><li class=""><a href="/spaces/pratham/tickets">Tickets</a></li><li class=""><a href="/spaces/pratham/milestones">Milestones</a></li><li class="current"><a href="/code/pratham/subversion/nodes">Source/SVN</a></li><li class=""><a href="/spaces/pratham/team">Team</a></li><li class=""><a href="/spaces/pratham/stream">Stream</a></li><li class=""><a href="/spaces/pratham/messages">Messages</a></li><li class=""><a href="/spaces/pratham/documents">Files</a></li><li class=""><a href="/spaces/pratham/chat_tool">Chat</a></li><li class=""><a href="/spaces/pratham/scrum?id=cOzjoK6jWr3RQ3eJe5afGb">StandUp</a></li><li class="search-field"><form accept-charset="UTF-8" action="/spaces/pratham/search" id="search-form" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div><input id="object_scope_top_right" name="object_scope" type="hidden" value="10" />
<input class="main-search" id="q" name="q" onfocus="this.value == 'Search this space' ? this.value = '' : true" size="15" type="text" value="Search this space" />
</form></li></ul>
      </div><!-- /main-menu-w -->

      <ul class='menu-submenu'><li><a href="/code/pratham/subversion/nodes" class="first selected">Browse</a></li><li><a href="/code/pratham/subversion/changesets" class="">Changesets</a></li><li><a href="/code/pratham/subversion/changesets/comments" class="">Comments</a></li><li><a href="/code/pratham/subversion/merge_requests" class="">Patch Requests</a></li><li><a href="/code/pratham/subversion/forks" class="">Fork Network</a></li><li><a href="/code/pratham/subversion/sites" class="">Sites</a></li><li><a href="/code/pratham/subversion/repo/instructions" class="">Instructions</a></li></ul><div class='cut'></div>

    
    <script type="text/javascript">
      if(!Breakout){var Breakout = {};}
      Breakout.space_wiki_name = "pratham";
        Breakout.user_id = "cYQMj8UOSr4kH8eJe4gwI3";
    </script>


    <div id="content" >
      
      <script type="text/javascript">
//<![CDATA[
hideFlashNotice();
//]]>
</script>
        <div class="repository-browser">
  <h1 class="icon-breadcrumb-path"><a href="/code/pratham/subversion/nodes?rev=19" class="root">root</a>/<span>OBC/trunk/Firmware/cc1020/cc1020.h</span><span>    <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
            width="110"
            height="14"
            id="clippy" >
    <param name="movie" value="/clippy.swf"/>
    <param name="allowScriptAccess" value="always" />
    <param name="quality" value="high" />
    <param name="scale" value="noscale" />
    <param NAME="FlashVars" value="text=http://www.assembla.com/code/pratham/subversion/nodes/OBC%2Ftrunk%2FFirmware%2Fcc1020%2Fcc1020.h?rev=19" />
    <param name="bgcolor" value="#FFFFFF" />
    <param name="wmode" value="transparent" />
    <embed src="/clippy.swf"
           width="110"
           height="14"
           name="clippy"
           quality="high"
           allowScriptAccess="always"
           type="application/x-shockwave-flash"
           pluginspage="http://www.macromedia.com/go/getflashplayer"
           FlashVars="text=http://www.assembla.com/code/pratham/subversion/nodes/OBC%2Ftrunk%2FFirmware%2Fcc1020%2Fcc1020.h?rev=19"
           bgcolor="#FFFFFF"
           wmode="transparent"
    />
    </object>
</span></h1>
  
<div class="commit-infobox">
  <div class="commit-options">
    <a href="/code/pratham/subversion/node/logs/OBC/trunk/Firmware/cc1020/cc1020.h?rev=19" class="revision-log" rel="nofollow">Revision log</a>
      <div style="margin-right: 10px;" class="small-icon-button">
        <a href="/code/pratham/subversion/node/blob/OBC/trunk/Firmware/cc1020/cc1020.h" class="view-icon" rel="nofollow">View as a web page</a>
      </div>

        <div style="margin-right: 10px;" class="small-icon-button">
    <a class="download-icon" href="#" onclick="nobotGoto('!/code/pratham/subversion/nodes/OBC/trunk/Firmware/cc1020/cc1020.h?_format=raw&amp;rev=19'); return false;">Download</a>
  </div>


    <div style="margin-right: 10px;" class="small-icon-button">
      <a href="/code/pratham/subversion/sites/new?path=OBC%2Ftrunk%2FFirmware%2Fcc1020%2Fcc1020.h" class="publish-icon" title="Publish as a Web site">Publish</a>
    </div>
  </div>

  <div class="committer-pic">
    <img alt="User picture" src="http://assets2.assembla.com/images/no-picture.png?1311939273" />
  </div>

  
<div class="commit-info">

    <p class="committer-info"><span>Author:</span> <a href="http://assembla.com/profile/chaitan3" tabindex="-1" target="_blank" title="Show Profile">chaitan3</a></p>

  <p class="committer-info"><span>Revision:</span> <a href="/code/pratham/subversion/changesets/11">11</a> (<span>«<a href="/code/pratham/subversion/nodes?rev=18">Previous</a></span>)</p>
  <p class="commit-date">(Oct 14 16:36 2010) 10 months ago</p>
</div>


  <p class="commit-description">
    <pre>Completed Slave code</pre>
  </p>
</div>

<div class="cut">&nbsp;</div>




    <a href="#" onclick="$(&quot;ln-num&quot;).toggle(); return false;">Show/hide line numbers</a>

    <table class="ln-code">
      <tbody class="full-width">
        <tr>
          <th id="ln-num" style="display: none;">
            <pre><a href="#ln1" class="block" id="ln1">1</a>
<a href="#ln2" class="block" id="ln2">2</a>
<a href="#ln3" class="block" id="ln3">3</a>
<a href="#ln4" class="block" id="ln4">4</a>
<a href="#ln5" class="block" id="ln5">5</a>
<a href="#ln6" class="block" id="ln6">6</a>
<a href="#ln7" class="block" id="ln7">7</a>
<a href="#ln8" class="block" id="ln8">8</a>
<a href="#ln9" class="block" id="ln9">9</a>
<a href="#ln10" class="block" id="ln10">10</a>
<a href="#ln11" class="block" id="ln11">11</a>
<a href="#ln12" class="block" id="ln12">12</a>
<a href="#ln13" class="block" id="ln13">13</a>
<a href="#ln14" class="block" id="ln14">14</a>
<a href="#ln15" class="block" id="ln15">15</a>
<a href="#ln16" class="block" id="ln16">16</a>
<a href="#ln17" class="block" id="ln17">17</a>
<a href="#ln18" class="block" id="ln18">18</a>
<a href="#ln19" class="block" id="ln19">19</a>
<a href="#ln20" class="block" id="ln20">20</a>
<a href="#ln21" class="block" id="ln21">21</a>
<a href="#ln22" class="block" id="ln22">22</a>
<a href="#ln23" class="block" id="ln23">23</a>
<a href="#ln24" class="block" id="ln24">24</a>
<a href="#ln25" class="block" id="ln25">25</a>
<a href="#ln26" class="block" id="ln26">26</a>
<a href="#ln27" class="block" id="ln27">27</a>
<a href="#ln28" class="block" id="ln28">28</a>
<a href="#ln29" class="block" id="ln29">29</a>
<a href="#ln30" class="block" id="ln30">30</a>
<a href="#ln31" class="block" id="ln31">31</a>
<a href="#ln32" class="block" id="ln32">32</a>
<a href="#ln33" class="block" id="ln33">33</a>
<a href="#ln34" class="block" id="ln34">34</a>
<a href="#ln35" class="block" id="ln35">35</a>
<a href="#ln36" class="block" id="ln36">36</a>
<a href="#ln37" class="block" id="ln37">37</a>
<a href="#ln38" class="block" id="ln38">38</a>
<a href="#ln39" class="block" id="ln39">39</a>
<a href="#ln40" class="block" id="ln40">40</a>
<a href="#ln41" class="block" id="ln41">41</a>
<a href="#ln42" class="block" id="ln42">42</a>
<a href="#ln43" class="block" id="ln43">43</a>
<a href="#ln44" class="block" id="ln44">44</a>
<a href="#ln45" class="block" id="ln45">45</a>
<a href="#ln46" class="block" id="ln46">46</a>
<a href="#ln47" class="block" id="ln47">47</a>
<a href="#ln48" class="block" id="ln48">48</a>
<a href="#ln49" class="block" id="ln49">49</a>
<a href="#ln50" class="block" id="ln50">50</a>
<a href="#ln51" class="block" id="ln51">51</a>
<a href="#ln52" class="block" id="ln52">52</a>
<a href="#ln53" class="block" id="ln53">53</a>
<a href="#ln54" class="block" id="ln54">54</a>
<a href="#ln55" class="block" id="ln55">55</a>
<a href="#ln56" class="block" id="ln56">56</a>
<a href="#ln57" class="block" id="ln57">57</a>
<a href="#ln58" class="block" id="ln58">58</a>
<a href="#ln59" class="block" id="ln59">59</a>
<a href="#ln60" class="block" id="ln60">60</a>
<a href="#ln61" class="block" id="ln61">61</a>
<a href="#ln62" class="block" id="ln62">62</a>
<a href="#ln63" class="block" id="ln63">63</a>
<a href="#ln64" class="block" id="ln64">64</a>
<a href="#ln65" class="block" id="ln65">65</a>
<a href="#ln66" class="block" id="ln66">66</a>
<a href="#ln67" class="block" id="ln67">67</a>
<a href="#ln68" class="block" id="ln68">68</a>
<a href="#ln69" class="block" id="ln69">69</a>
<a href="#ln70" class="block" id="ln70">70</a>
<a href="#ln71" class="block" id="ln71">71</a>
<a href="#ln72" class="block" id="ln72">72</a>
<a href="#ln73" class="block" id="ln73">73</a>
<a href="#ln74" class="block" id="ln74">74</a>
<a href="#ln75" class="block" id="ln75">75</a>
<a href="#ln76" class="block" id="ln76">76</a>
<a href="#ln77" class="block" id="ln77">77</a>
<a href="#ln78" class="block" id="ln78">78</a>
<a href="#ln79" class="block" id="ln79">79</a>
<a href="#ln80" class="block" id="ln80">80</a>
<a href="#ln81" class="block" id="ln81">81</a>
<a href="#ln82" class="block" id="ln82">82</a>
<a href="#ln83" class="block" id="ln83">83</a>
<a href="#ln84" class="block" id="ln84">84</a>
<a href="#ln85" class="block" id="ln85">85</a>
<a href="#ln86" class="block" id="ln86">86</a>
<a href="#ln87" class="block" id="ln87">87</a>
<a href="#ln88" class="block" id="ln88">88</a>
<a href="#ln89" class="block" id="ln89">89</a>
<a href="#ln90" class="block" id="ln90">90</a>
<a href="#ln91" class="block" id="ln91">91</a>
<a href="#ln92" class="block" id="ln92">92</a>
<a href="#ln93" class="block" id="ln93">93</a>
<a href="#ln94" class="block" id="ln94">94</a>
<a href="#ln95" class="block" id="ln95">95</a>
<a href="#ln96" class="block" id="ln96">96</a>
<a href="#ln97" class="block" id="ln97">97</a>
<a href="#ln98" class="block" id="ln98">98</a>
<a href="#ln99" class="block" id="ln99">99</a>
<a href="#ln100" class="block" id="ln100">100</a>
<a href="#ln101" class="block" id="ln101">101</a>
<a href="#ln102" class="block" id="ln102">102</a>
<a href="#ln103" class="block" id="ln103">103</a>
<a href="#ln104" class="block" id="ln104">104</a>
<a href="#ln105" class="block" id="ln105">105</a>
<a href="#ln106" class="block" id="ln106">106</a>
<a href="#ln107" class="block" id="ln107">107</a>
<a href="#ln108" class="block" id="ln108">108</a>
<a href="#ln109" class="block" id="ln109">109</a>
<a href="#ln110" class="block" id="ln110">110</a>
<a href="#ln111" class="block" id="ln111">111</a>
<a href="#ln112" class="block" id="ln112">112</a>
<a href="#ln113" class="block" id="ln113">113</a>
<a href="#ln114" class="block" id="ln114">114</a>
<a href="#ln115" class="block" id="ln115">115</a>
<a href="#ln116" class="block" id="ln116">116</a>
<a href="#ln117" class="block" id="ln117">117</a>
<a href="#ln118" class="block" id="ln118">118</a>
<a href="#ln119" class="block" id="ln119">119</a>
<a href="#ln120" class="block" id="ln120">120</a>
<a href="#ln121" class="block" id="ln121">121</a></pre></th>
          <td><pre class="prettyprint lang-h">
// Default RF setups, stored in Flash
    
// SmartRF Studio v5.3.0.0

// Device: CC1020

// System parameters:
// X-tal frequency: 14.745600 MHz	Internal
// X-tal accuracy: +/-  5 ppm
// RF frequency A: 434.052500 MHz	Active  	Rx
// RF frequency B: 434.052500 MHz	Inactive	Tx
// Frequency separation: 4.950 kHz
// Data rate: 4.800 kBaud
// Data Format: NRZ		Accurate
// RF output power: +10 dBm
// Channel width: 25 kHz
// Modulation: FSK		Dithering enabled
// Lock: Continuous
// Carrier sense offset:   0 dBm	DCLK squelch disabled
// Operator Mode: Rx

const char DefaultConfig433[32] =
{
  0x0F,  // 0x01, INTERFACE		//DCLK_CS will be used in RX mode
  0xFF,  // 0x02, RESET
  0x8F,  // 0x03, SEQUENCING
  0x39,  // 0x04, FREQ_2A  	39
  0xF0,  // 0x05, FREQ_1A	F0
  0x0F,  // 0x06, FREQ_0A	0F
  0x3B,  // 0x07, CLOCK_A
  0x39,  // 0x08, FREQ_2B   39
  0xFA,  // 0x09, FREQ_1B   FA
  0xB9,  // 0x0A, FREQ_0B   B9
  0x3B,  // 0x0B, CLOCK_B
  0x44,  // 0x0C, VCO
  0x50,  // 0x0D, MODEM
  0x0B,  // 0x0E, DEVIATION
  0xCC,  // 0x0F, AFC_CONTROL
  0x2F,  // 0x10, FILTER
  0x61,  // 0x11, VGA1
  0x55,  // 0x12, VGA2
  0x2F,  // 0x13, VGA3
  0x2D,  // 0x14, VGA4			Carrier Sense Threshold Level = 5dB
  0x10,  // 0x15, LOCK          // When not used, set as high
  0x78,  // 0x16, FRONTEND
  0x47,  // 0x17, ANALOG, RX=47/TX=47
  0x14,  // 0x18, BUFF_SWING
  0x22,  // 0x19, BUFF_CURRENT
  0xAE,  // 0x1A, PLL_BW
  0x34,  // 0x1B, CALIBRATE
  0xF0,  // 0x1C, PA_POWER		// 10dbm output power
  0x00,  // 0x1D, MATCH
  0x00,  // 0x1E, PHASE_COMP
  0x00,  // 0x1F, GAIN_COMP
  0x00   // 0x20, POWERDOWN
};


/* Constants defined for CC1020 */

/* Register addresses */

#define CC1020_MAIN            0x00
#define CC1020_INTERFACE       0x01
#define CC1020_RESET           0x02
#define CC1020_SEQUENCING      0x03
#define CC1020_FREQ_2A         0x04
#define CC1020_FREQ_1A         0x05
#define CC1020_FREQ_0A         0x06
#define CC1020_CLOCK_A         0x07
#define CC1020_FREQ_2B         0x08
#define CC1020_FREQ_1B         0x09
#define CC1020_FREQ_0B         0x0A
#define CC1020_CLOCK_B         0x0B
#define CC1020_VCO             0x0C
#define CC1020_MODEM           0x0D
#define CC1020_DEVIATION       0x0E
#define CC1020_AFC_CONTROL     0x0F
#define CC1020_FILTER          0x10
#define CC1020_VGA1            0x11
#define CC1020_VGA2            0x12
#define CC1020_VGA3            0x13
#define CC1020_VGA4            0x14
#define CC1020_LOCK            0x15
#define CC1020_FRONTEND        0x16
#define CC1020_ANALOG          0x17
#define CC1020_BUFF_SWING      0x18
#define CC1020_BUFF_CURRENT    0x19
#define CC1020_PLL_BW          0x1A
#define CC1020_CALIBRATE       0x1B
#define CC1020_PA_POWER        0x1C
#define CC1020_MATCH           0x1D
#define CC1020_PHASE_COMP      0x1E
#define CC1020_GAIN_COMP       0x1F
#define CC1020_POWERDOWN       0x20
#define CC1020_TEST1           0x21
#define CC1020_TEST2           0x22
#define CC1020_TEST3           0x23
#define CC1020_TEST4           0x24
#define CC1020_TEST5           0x25
#define CC1020_TEST6           0x26
#define CC1020_TEST7           0x27
#define CC1020_STATUS          0x40
#define CC1020_RESET_DONE      0x41
#define CC1020_RSSI            0x42
#define CC1020_AFC             0x43
#define CC1020_GAUSS_FILTER    0x44
#define CC1020_STATUS1         0x45
#define CC1020_STATUS2         0x46
#define CC1020_STATUS3         0x47
#define CC1020_STATUS4         0x48
#define CC1020_STATUS5         0x49
#define CC1020_STATUS6         0x4A
#define CC1020_STATUS7         0x4B

#define PA_POWER        0x0F			//0 dbm output power
// Constants for CC1020

#define TXANALOG 0x47
</pre></td>
        </tr>
      </tbody>
    </table>
</div>

<script type="text/javascript">
//<![CDATA[
if (window.location.href.split("#").length != 1) { $("ln-num").show(); }
//]]>
</script>

  <script type="text/javascript">
//<![CDATA[
prettyPrint()
//]]>
</script>



    </div><!-- /content -->

      

    <div class="push-app"></div>
    </div><!-- /b-wrapper -->
    <div id="footer-w">
  <div class="tutorial-and-bookmark">
      <div class="video-link" style="text-align: center;"><a href="/features/popup_video?video=12" rel="fancybox">Watch our tutorial video for the Source/SVN Tool</a></div><div class='promotion'>Powered by WANdisco Subversion. Information on WANdisco Subversion for on-site installation <a href='http://www.wandisco.com'>here</a></div>
  </div>

  

  <div id="footer">

    <p>
      <a href="/">Home</a>
      / <a href="/community">Community</a>
      / <a href="http://www.assembla.com/wiki/show/c8A2BGQEWr2RUvaaeP0Qfc">Documentation</a>
        / <a href="http://forum.assembla.com/" target="_blank">Report bugs</a>
        / <a href="http://feedback.assembla.com/" target="_blank">Send us Suggestions</a>
        / <a href="/spaces/pratham/prepare_copy">Copy this space</a>
    </p>

      <p>
        <a href="/catalog/1">Get a Space</a>
      </p>

    <p id="copyr-contact">
     Code repository is powered by Assembla Workspaces. <a href="/">Learn More</a>
</p>

  </div><!-- /footer -->
</div><!-- /footer-w -->

    

      


  </body>
</html>



