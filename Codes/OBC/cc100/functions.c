



  



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
  <head>
    <script type="text/javascript">
//<![CDATA[
document.domain = 'assembla.com';
//]]>
</script>
    <title>OBC/trunk/Firmware/cc1020/functions.c | Source/SVN | Assembla</title>
    <link href="http://assets2.assembla.com/favicon.ico?1306321271" type="image/x-icon" rel="shortcut icon" />
    <link href="http://assets2.assembla.com/favicon.ico?1306321271" type="image/x-icon" rel="icon" />
    <meta name="csrf-param" content="authenticity_token"/>
<meta name="csrf-token" content="T/RDNnV5MgB6KmIe0UcZSlGFBQhbF8cru30lmZBCvT4="/>
    <link href="http://assets0.assembla.com/stylesheets/base_app_and_alerts_packaged.css?1311939604" media="all" rel="stylesheet" type="text/css" />
    
    
    <link href="http://assets1.assembla.com/stylesheets/code_packaged.css?1311939604" media="all" rel="stylesheet" type="text/css" />  

      <style type="text/css" media="all" rel="stylesheet" id="branded_css">
        
        
      </style>
    
    <link href="http://assets2.assembla.com/stylesheets/print.css?1311939273" media="print" rel="stylesheet" type="text/css" />

    <!--[if IE 7]>
        <link rel="stylesheet" type="text/css" href="/stylesheets/ie7.css">
    <![endif]-->

    <!--[if lte IE 8]>
        <link rel="stylesheet" type="text/css" href="/stylesheets/ie8.css">
    <![endif]-->

    <script src="http://assets1.assembla.com/javascripts/base_packaged.js?1311939592" type="text/javascript"></script>
    
    
    
    <script src="http://assets0.assembla.com/javascripts/code_packaged.js?1311939594" type="text/javascript"></script>  <script type="text/javascript">
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
  <h1 class="icon-breadcrumb-path"><a href="/code/pratham/subversion/nodes?rev=19" class="root">root</a>/<span>OBC/trunk/Firmware/cc1020/functions.c</span><span>    <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
            width="110"
            height="14"
            id="clippy" >
    <param name="movie" value="/clippy.swf"/>
    <param name="allowScriptAccess" value="always" />
    <param name="quality" value="high" />
    <param name="scale" value="noscale" />
    <param NAME="FlashVars" value="text=http://www.assembla.com/code/pratham/subversion/nodes/OBC%2Ftrunk%2FFirmware%2Fcc1020%2Ffunctions.c?rev=19" />
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
           FlashVars="text=http://www.assembla.com/code/pratham/subversion/nodes/OBC%2Ftrunk%2FFirmware%2Fcc1020%2Ffunctions.c?rev=19"
           bgcolor="#FFFFFF"
           wmode="transparent"
    />
    </object>
</span></h1>
  
<div class="commit-infobox">
  <div class="commit-options">
    <a href="/code/pratham/subversion/node/logs/OBC/trunk/Firmware/cc1020/functions.c?rev=19" class="revision-log" rel="nofollow">Revision log</a>
      <div style="margin-right: 10px;" class="small-icon-button">
        <a href="/code/pratham/subversion/node/blob/OBC/trunk/Firmware/cc1020/functions.c" class="view-icon" rel="nofollow">View as a web page</a>
      </div>

        <div style="margin-right: 10px;" class="small-icon-button">
    <a class="download-icon" href="#" onclick="nobotGoto('!/code/pratham/subversion/nodes/OBC/trunk/Firmware/cc1020/functions.c?_format=raw&amp;rev=19'); return false;">Download</a>
  </div>


    <div style="margin-right: 10px;" class="small-icon-button">
      <a href="/code/pratham/subversion/sites/new?path=OBC%2Ftrunk%2FFirmware%2Fcc1020%2Ffunctions.c" class="publish-icon" title="Publish as a Web site">Publish</a>
    </div>
  </div>

  <div class="committer-pic">
    <img alt="User picture" src="http://assets1.assembla.com/images/no-picture.png?1311939273" />
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
<a href="#ln121" class="block" id="ln121">121</a>
<a href="#ln122" class="block" id="ln122">122</a>
<a href="#ln123" class="block" id="ln123">123</a>
<a href="#ln124" class="block" id="ln124">124</a>
<a href="#ln125" class="block" id="ln125">125</a>
<a href="#ln126" class="block" id="ln126">126</a>
<a href="#ln127" class="block" id="ln127">127</a>
<a href="#ln128" class="block" id="ln128">128</a>
<a href="#ln129" class="block" id="ln129">129</a>
<a href="#ln130" class="block" id="ln130">130</a>
<a href="#ln131" class="block" id="ln131">131</a>
<a href="#ln132" class="block" id="ln132">132</a>
<a href="#ln133" class="block" id="ln133">133</a>
<a href="#ln134" class="block" id="ln134">134</a>
<a href="#ln135" class="block" id="ln135">135</a>
<a href="#ln136" class="block" id="ln136">136</a>
<a href="#ln137" class="block" id="ln137">137</a>
<a href="#ln138" class="block" id="ln138">138</a>
<a href="#ln139" class="block" id="ln139">139</a>
<a href="#ln140" class="block" id="ln140">140</a>
<a href="#ln141" class="block" id="ln141">141</a>
<a href="#ln142" class="block" id="ln142">142</a>
<a href="#ln143" class="block" id="ln143">143</a>
<a href="#ln144" class="block" id="ln144">144</a>
<a href="#ln145" class="block" id="ln145">145</a>
<a href="#ln146" class="block" id="ln146">146</a>
<a href="#ln147" class="block" id="ln147">147</a>
<a href="#ln148" class="block" id="ln148">148</a>
<a href="#ln149" class="block" id="ln149">149</a>
<a href="#ln150" class="block" id="ln150">150</a>
<a href="#ln151" class="block" id="ln151">151</a>
<a href="#ln152" class="block" id="ln152">152</a>
<a href="#ln153" class="block" id="ln153">153</a>
<a href="#ln154" class="block" id="ln154">154</a>
<a href="#ln155" class="block" id="ln155">155</a>
<a href="#ln156" class="block" id="ln156">156</a>
<a href="#ln157" class="block" id="ln157">157</a>
<a href="#ln158" class="block" id="ln158">158</a>
<a href="#ln159" class="block" id="ln159">159</a>
<a href="#ln160" class="block" id="ln160">160</a>
<a href="#ln161" class="block" id="ln161">161</a>
<a href="#ln162" class="block" id="ln162">162</a>
<a href="#ln163" class="block" id="ln163">163</a>
<a href="#ln164" class="block" id="ln164">164</a>
<a href="#ln165" class="block" id="ln165">165</a>
<a href="#ln166" class="block" id="ln166">166</a>
<a href="#ln167" class="block" id="ln167">167</a>
<a href="#ln168" class="block" id="ln168">168</a>
<a href="#ln169" class="block" id="ln169">169</a>
<a href="#ln170" class="block" id="ln170">170</a>
<a href="#ln171" class="block" id="ln171">171</a>
<a href="#ln172" class="block" id="ln172">172</a>
<a href="#ln173" class="block" id="ln173">173</a>
<a href="#ln174" class="block" id="ln174">174</a>
<a href="#ln175" class="block" id="ln175">175</a>
<a href="#ln176" class="block" id="ln176">176</a>
<a href="#ln177" class="block" id="ln177">177</a>
<a href="#ln178" class="block" id="ln178">178</a>
<a href="#ln179" class="block" id="ln179">179</a>
<a href="#ln180" class="block" id="ln180">180</a>
<a href="#ln181" class="block" id="ln181">181</a>
<a href="#ln182" class="block" id="ln182">182</a>
<a href="#ln183" class="block" id="ln183">183</a>
<a href="#ln184" class="block" id="ln184">184</a>
<a href="#ln185" class="block" id="ln185">185</a>
<a href="#ln186" class="block" id="ln186">186</a>
<a href="#ln187" class="block" id="ln187">187</a>
<a href="#ln188" class="block" id="ln188">188</a>
<a href="#ln189" class="block" id="ln189">189</a>
<a href="#ln190" class="block" id="ln190">190</a>
<a href="#ln191" class="block" id="ln191">191</a>
<a href="#ln192" class="block" id="ln192">192</a>
<a href="#ln193" class="block" id="ln193">193</a>
<a href="#ln194" class="block" id="ln194">194</a>
<a href="#ln195" class="block" id="ln195">195</a>
<a href="#ln196" class="block" id="ln196">196</a>
<a href="#ln197" class="block" id="ln197">197</a>
<a href="#ln198" class="block" id="ln198">198</a>
<a href="#ln199" class="block" id="ln199">199</a>
<a href="#ln200" class="block" id="ln200">200</a>
<a href="#ln201" class="block" id="ln201">201</a>
<a href="#ln202" class="block" id="ln202">202</a>
<a href="#ln203" class="block" id="ln203">203</a>
<a href="#ln204" class="block" id="ln204">204</a>
<a href="#ln205" class="block" id="ln205">205</a>
<a href="#ln206" class="block" id="ln206">206</a>
<a href="#ln207" class="block" id="ln207">207</a>
<a href="#ln208" class="block" id="ln208">208</a>
<a href="#ln209" class="block" id="ln209">209</a>
<a href="#ln210" class="block" id="ln210">210</a>
<a href="#ln211" class="block" id="ln211">211</a>
<a href="#ln212" class="block" id="ln212">212</a>
<a href="#ln213" class="block" id="ln213">213</a>
<a href="#ln214" class="block" id="ln214">214</a>
<a href="#ln215" class="block" id="ln215">215</a>
<a href="#ln216" class="block" id="ln216">216</a>
<a href="#ln217" class="block" id="ln217">217</a>
<a href="#ln218" class="block" id="ln218">218</a>
<a href="#ln219" class="block" id="ln219">219</a>
<a href="#ln220" class="block" id="ln220">220</a>
<a href="#ln221" class="block" id="ln221">221</a>
<a href="#ln222" class="block" id="ln222">222</a>
<a href="#ln223" class="block" id="ln223">223</a>
<a href="#ln224" class="block" id="ln224">224</a>
<a href="#ln225" class="block" id="ln225">225</a>
<a href="#ln226" class="block" id="ln226">226</a>
<a href="#ln227" class="block" id="ln227">227</a></pre></th>
          <td><pre class="prettyprint lang-c">
#include &quot;common.h&quot;
#include &quot;spi.h&quot;
#include &quot;common.h&quot;
#include &quot;cc1020.h&quot;
#include &quot;functions.h&quot;

int init_CC1020 (void){
  
  init_SPI_trans(CC1020);
  sbi(PORT_CS, CC1020);
  
  SetupCC1020PD();
  ResetCC1020();//CC is still in PD (Power_Down mode) after reset
  SetupCC1020Allregisters();
  WakeUpCC1020ToTX(TXANALOG);
  CalibrateCC1020 (PA_POWER);
  
  WakeUpCC1020ToTX(TXANALOG);													
  return SetupCC1020TX(TXANALOG,PA_POWER);
}

/****************************************************************************/
/*  This routine writes to a single CC1020 register                         */
/****************************************************************************/

void WriteToCC1020Register(unsigned char addr, unsigned char data)
{
  cbi(PORT_CS, CC1020);
  
  addr = (addr &lt;&lt; 1) | 0x01;
  SPI_transfer(addr);
  SPI_transfer(data);
  
  sbi(PORT_CS, CC1020);
  
}
/****************************************************************************/
/*  This routine reads from a single CC1020 register                        */
/****************************************************************************/

unsigned char ReadFromCC1020Register(unsigned char addr)
{
	char Value;
  
  cbi(PORT_CS, CC1020);
  
  addr = (addr &lt;&lt; 1) &amp; 0xFE;
  SPI_transfer(addr);
  
  Value = SPI_transfer(0xFF);
  
  sbi(PORT_CS, CC1020);
	return Value;
}

/****************************************************************************/
/*  This routine puts the CC1020 into power down mode. Use WakeUpCC1020ToRX */
/*  followed by SetupCC1020RX or WakeupCC1020ToTX followed by SetupCC1020TX */
/*  to wake up from power down                                              */
/****************************************************************************/

void SetupCC1020PD(void)
{
  // Put CC1020 into power-down
  WriteToCC1020Register(CC1020_MAIN,0x1F);

  // Turn off PA to minimise current draw
  WriteToCC1020Register(CC1020_PA_POWER,0x00);
}


/****************************************************************************/
/*  This routine resets the CC1020, clearing all registers.                 */
/****************************************************************************/  

void ResetCC1020(void)
{
  // Reset CC1020
  WriteToCC1020Register(CC1020_MAIN, 0x0E);

  // Bring CC1020 out of reset
  WriteToCC1020Register(CC1020_MAIN, 0x1F);
}


/****************************************************************************/
/*  This routine configures all CC1020 registers as per values stored in DefaultConfig433[] */
/****************************************************************************/

void SetupCC1020Allregisters(void)
{
  char counter, value;
  
  for(counter = 0x01; counter &lt;= 0x20; counter++)
  {
    value = DefaultConfig433[counter - 1];				// For Transmitter as well as Receiver
    WriteToCC1020Register(counter, value);
  }
}


/****************************************************************************/
/*  This routine wakes the CC1020 up from PD mode to TX mode. CC is still in 
	power down mode 		*/
/****************************************************************************/

void WakeUpCC1020ToTX(char TXANALOG1)
{
 
  // Turn on xtal oscillator core
  WriteToCC1020Register(CC1020_MAIN,0xDB);

  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,TXANALOG1);

  // Insert wait routine here, must wait for xtal oscillator to stabilise, 
  // typically takes 2-5ms.
	_delay_ms(3);

  // Turn on bias generator
  WriteToCC1020Register(CC1020_MAIN,0xD9);

  // Wait for 150 usec
	_delay_us(150);		

  // Turn on frequency synthesiser
  WriteToCC1020Register(CC1020_MAIN,0xD1);
}

/****************************************************************************/
/*  This routine calibrates the CC1020                                      */
/*  Returns 0 if calibration fails, non-zero otherwise. Checks the LOCK     */
/*  to check for success.                                                   */
/****************************************************************************/

int CalibrateCC1020(char PA_POWER1)
{
  volatile int TimeOutCounter;
  volatile int nCalAttempt;

  // Turn off PA to avoid spurs during calibration in TX mode
  WriteToCC1020Register(CC1020_PA_POWER,0x00);

  // Calibrate, and re-calibrate if necessary:
  for (nCalAttempt = CAL_ATTEMPT_MAX; nCalAttempt &gt; 0; nCalAttempt--) 
  {

    // Start calibration
    WriteToCC1020Register(CC1020_CALIBRATE,0xB4);            // verified with cc1020 datasheet
	
    // Wait for 100 usec. As given errata notes.
    _delay_us(100);

    // Monitor calibration complete bit in STATUS register
    // CAL_COMPLETE bit set to 1 when calibration is complete
    // Waiting time according to register settings is approx 27ms. Ref_freq=fosc/2 and CAL_WAIT = 11
    // We are waiting for 30ms
    for(TimeOutCounter = 30; ((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x80) == 0x00) &amp;&amp; (TimeOutCounter &gt; 0); TimeOutCounter--)
      _delay_ms(1);
    
    // Monitor lock
    // LOCK_CONTINUOUS bit in STATUS register is set to 1 when PLL is in LOCK
    for(TimeOutCounter = 30; ((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x10) == 0x00) &amp;&amp; (TimeOutCounter &gt; 0); TimeOutCounter--)
      _delay_ms(1);	

    // Abort further recalibration attempts if successful LOCK
    if((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x10) == 0x10) 
		 break;
  }

  // Restore PA setting
  WriteToCC1020Register(CC1020_PA_POWER, PA_POWER1);

  // Return state of LOCK_CONTINUOUS bit
  return ((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x10) == 0x10);
}


/****************************************************************************/
/*  This routine puts the CC1020 into TX mode (from RX). When switching to  */
/*  TX from PD, use WakeupCC1020ToTX first                                  */
/****************************************************************************/

char SetupCC1020TX(char TXANALOG1, char PA_POWER1)
{
  volatile int TimeOutCounter;
  int lock_status;

  // Turn off PA to avoid frequency splatter
  WriteToCC1020Register(CC1020_PA_POWER,0x00);

  // Setup bias current adjustment
  WriteToCC1020Register(CC1020_ANALOG,TXANALOG1);

  // Switch into TX, switch to freq. reg B
  WriteToCC1020Register(CC1020_MAIN,0xC1);     // TX Coming out of Power down at this stage

  // Monitor lock
  // LOCK_CONTINUOUS bit set to 1 when PLL is in LOCK
  for(TimeOutCounter = 30; ((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x10) == 0x00) &amp;&amp; (TimeOutCounter &gt; 0); TimeOutCounter--)
    _delay_ms(1);
	
  // If PLL in lock 
  if((ReadFromCC1020Register(CC1020_STATUS) &amp; 0x10) == 0x10)
    lock_status = TRUE;
  else	// if PLL is not locked then Recalibrate
  {
    // If recalibration ok
		if(CalibrateCC1020(PA_POWER1))
      lock_status = TRUE;
    else
      lock_status = FALSE;
  }

  // Restore PA setting
  WriteToCC1020Register(CC1020_PA_POWER,PA_POWER1);

  // Turn OFF DCLK_CS (Carrier Sense Squelch) in TX
  WriteToCC1020Register(CC1020_INTERFACE,ReadFromCC1020Register(CC1020_INTERFACE) &amp; (~0x10));
  
  // Configure LOCK pin to continuous lock status. Active low indicates PLL in lock
  WriteToCC1020Register(CC1020_LOCK,0x20);

  // Return LOCK status to application
  return (lock_status);
}</pre></td>
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



