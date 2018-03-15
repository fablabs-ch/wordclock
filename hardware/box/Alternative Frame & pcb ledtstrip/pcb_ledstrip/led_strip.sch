<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.4.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting keepoldvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="led_strip">
<packages>
<package name="LED_STRIP">
<smd name="DATAS" x="0" y="0" dx="5" dy="2" layer="1"/>
<wire x1="-3.04" y1="-4.58" x2="3.04" y2="-4.58" width="0.127" layer="21"/>
<wire x1="3.04" y1="-4.58" x2="3.04" y2="4.58" width="0.127" layer="21"/>
<wire x1="3.04" y1="4.58" x2="-3.04" y2="4.58" width="0.127" layer="21"/>
<smd name="P$1" x="0" y="3" dx="5" dy="2" layer="1"/>
<smd name="P$2" x="0" y="-3" dx="5" dy="2" layer="1"/>
<wire x1="-3.04" y1="4.58" x2="-3.04" y2="-4.58" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="LED_STRIP">
<pin name="VCC" x="-10.16" y="5.08" length="middle"/>
<pin name="DATAS" x="-10.16" y="0" length="middle"/>
<pin name="GND" x="-10.16" y="-5.08" length="middle"/>
<wire x1="-7.62" y1="7.62" x2="-7.62" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-7.62" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="-7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="-7.62" y2="7.62" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LED_STRIP" prefix="LED_STRIP">
<gates>
<gate name="G$1" symbol="LED_STRIP" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LED_STRIP">
<connects>
<connect gate="G$1" pin="DATAS" pad="DATAS"/>
<connect gate="G$1" pin="GND" pad="P$1"/>
<connect gate="G$1" pin="VCC" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-samtec">
<description>&lt;b&gt;Samtec Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="SSW-101-02-S-S">
<description>&lt;b&gt;THROUGH-HOLE .025" SQ POST SOCKET&lt;/b&gt;&lt;p&gt;
Source: Samtec SSW.pdf</description>
<wire x1="-1.399" y1="1.155" x2="1.399" y2="1.155" width="0.2032" layer="21"/>
<wire x1="1.399" y1="1.155" x2="1.399" y2="-1.155" width="0.2032" layer="21"/>
<wire x1="1.399" y1="-1.155" x2="-1.399" y2="-1.155" width="0.2032" layer="21"/>
<wire x1="-1.399" y1="-1.155" x2="-1.399" y2="1.155" width="0.2032" layer="21"/>
<wire x1="-0.745" y1="0.755" x2="0.755" y2="0.755" width="0.2032" layer="51"/>
<wire x1="0.755" y1="0.755" x2="0.755" y2="-0.745" width="0.2032" layer="51"/>
<wire x1="0.755" y1="-0.745" x2="-0.745" y2="-0.745" width="0.2032" layer="51"/>
<wire x1="-0.745" y1="-0.745" x2="-0.745" y2="0.755" width="0.2032" layer="51"/>
<pad name="1" x="0" y="0" drill="1" diameter="1.5" shape="octagon"/>
<text x="-1.905" y="-1.27" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="3.175" y="-1.27" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
</package>
<package name="SSW-101-02-S-S-RA">
<description>&lt;b&gt;THROUGH-HOLE .025" SQ POST SOCKET&lt;/b&gt;&lt;p&gt;
Source: Samtec SSW.pdf</description>
<wire x1="-1.399" y1="-8.396" x2="1.399" y2="-8.396" width="0.2032" layer="21"/>
<wire x1="1.399" y1="-8.396" x2="1.399" y2="-0.106" width="0.2032" layer="21"/>
<wire x1="1.399" y1="-0.106" x2="-1.399" y2="-0.106" width="0.2032" layer="21"/>
<wire x1="-1.399" y1="-0.106" x2="-1.399" y2="-8.396" width="0.2032" layer="21"/>
<pad name="1" x="0" y="1.524" drill="1" diameter="1.5" shape="octagon"/>
<text x="-1.905" y="-7.62" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="3.175" y="-7.62" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-0.254" y1="0" x2="0.254" y2="1.778" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="FPINV">
<wire x1="-1.778" y1="0.508" x2="0" y2="0.508" width="0.254" layer="94"/>
<wire x1="0" y1="0.508" x2="0" y2="-0.508" width="0.254" layer="94"/>
<wire x1="0" y1="-0.508" x2="-1.778" y2="-0.508" width="0.254" layer="94"/>
<text x="-2.54" y="2.54" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.048" y="0.762" size="1.524" layer="95" rot="R180">&gt;NAME</text>
<pin name="1" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SSW-101-02-S-S" prefix="X">
<description>&lt;b&gt;THROUGH-HOLE .025" SQ POST SOCKET&lt;/b&gt;&lt;p&gt;
Source: Samtec SSW.pdf</description>
<gates>
<gate name="-1" symbol="FPINV" x="0" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="SSW-101-02-S-S">
<connects>
<connect gate="-1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="SSW-101-02-S-S" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="11P9336" constant="no"/>
</technology>
</technologies>
</device>
<device name="-RA" package="SSW-101-02-S-S-RA">
<connects>
<connect gate="-1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="SSW-101-02-S-S-RA" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="11P9337" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="24" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="23" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="13" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="18" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="16" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="15" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="14" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="17" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="22" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="21" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="20" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="19" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="VCC" library="con-samtec" deviceset="SSW-101-02-S-S" device="" value="VCC"/>
<part name="12" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="11" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="1" library="led_strip" deviceset="LED_STRIP" device="" value="1"/>
<part name="6" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="4" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="3" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="2" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="5" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="10" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="9" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="8" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="7" library="led_strip" deviceset="LED_STRIP" device=""/>
<part name="GND" library="con-samtec" deviceset="SSW-101-02-S-S" device="" value="GND"/>
<part name="DIN" library="con-samtec" deviceset="SSW-101-02-S-S" device="" value="DATA"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="24" gate="G$1" x="-88.9" y="0"/>
<instance part="23" gate="G$1" x="-88.9" y="17.78"/>
<instance part="13" gate="G$1" x="-88.9" y="195.58"/>
<instance part="18" gate="G$1" x="-88.9" y="106.68"/>
<instance part="16" gate="G$1" x="-88.9" y="142.24"/>
<instance part="15" gate="G$1" x="-88.9" y="160.02"/>
<instance part="14" gate="G$1" x="-88.9" y="177.8"/>
<instance part="17" gate="G$1" x="-88.9" y="124.46"/>
<instance part="22" gate="G$1" x="-88.9" y="35.56"/>
<instance part="21" gate="G$1" x="-88.9" y="53.34"/>
<instance part="20" gate="G$1" x="-88.9" y="71.12"/>
<instance part="19" gate="G$1" x="-88.9" y="88.9"/>
<instance part="VCC" gate="-1" x="-142.24" y="200.66" smashed="yes">
<attribute name="NAME" x="-145.288" y="201.422" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="12" gate="G$1" x="-68.58" y="0" rot="MR0"/>
<instance part="11" gate="G$1" x="-68.58" y="17.78" rot="MR0"/>
<instance part="1" gate="G$1" x="-68.58" y="195.58" rot="MR0"/>
<instance part="6" gate="G$1" x="-68.58" y="106.68" rot="MR0"/>
<instance part="4" gate="G$1" x="-68.58" y="142.24" rot="MR0"/>
<instance part="3" gate="G$1" x="-68.58" y="160.02" rot="MR0"/>
<instance part="2" gate="G$1" x="-68.58" y="177.8" rot="MR0"/>
<instance part="5" gate="G$1" x="-68.58" y="124.46" rot="MR0"/>
<instance part="10" gate="G$1" x="-68.58" y="35.56" rot="MR0"/>
<instance part="9" gate="G$1" x="-68.58" y="53.34" rot="MR0"/>
<instance part="8" gate="G$1" x="-68.58" y="71.12" rot="MR0"/>
<instance part="7" gate="G$1" x="-68.58" y="88.9" rot="MR0"/>
<instance part="GND" gate="-1" x="-15.24" y="190.5" smashed="yes" rot="MR0">
<attribute name="NAME" x="-12.192" y="191.262" size="1.524" layer="95" rot="MR180"/>
</instance>
<instance part="DIN" gate="-1" x="-124.46" y="195.58" smashed="yes" rot="MR180">
<attribute name="NAME" x="-127.508" y="194.818" size="1.524" layer="95" rot="MR0"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="VCC" gate="-1" pin="1"/>
<pinref part="13" gate="G$1" pin="VCC"/>
<wire x1="-139.7" y1="200.66" x2="-137.16" y2="200.66" width="0.1524" layer="91"/>
<pinref part="14" gate="G$1" pin="VCC"/>
<wire x1="-137.16" y1="200.66" x2="-99.06" y2="200.66" width="0.1524" layer="91"/>
<wire x1="-99.06" y1="182.88" x2="-137.16" y2="182.88" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="182.88" x2="-137.16" y2="200.66" width="0.1524" layer="91"/>
<junction x="-137.16" y="200.66"/>
<pinref part="15" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="165.1" x2="-137.16" y2="165.1" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="165.1" x2="-137.16" y2="182.88" width="0.1524" layer="91"/>
<junction x="-137.16" y="182.88"/>
<pinref part="16" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="147.32" x2="-137.16" y2="147.32" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="147.32" x2="-137.16" y2="165.1" width="0.1524" layer="91"/>
<junction x="-137.16" y="165.1"/>
<pinref part="17" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="129.54" x2="-137.16" y2="129.54" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="129.54" x2="-137.16" y2="147.32" width="0.1524" layer="91"/>
<junction x="-137.16" y="147.32"/>
<pinref part="18" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="111.76" x2="-137.16" y2="111.76" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="111.76" x2="-137.16" y2="129.54" width="0.1524" layer="91"/>
<junction x="-137.16" y="129.54"/>
<pinref part="19" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="93.98" x2="-137.16" y2="93.98" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="93.98" x2="-137.16" y2="111.76" width="0.1524" layer="91"/>
<junction x="-137.16" y="111.76"/>
<pinref part="20" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="76.2" x2="-137.16" y2="76.2" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="76.2" x2="-137.16" y2="93.98" width="0.1524" layer="91"/>
<junction x="-137.16" y="93.98"/>
<pinref part="21" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="58.42" x2="-137.16" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="58.42" x2="-137.16" y2="76.2" width="0.1524" layer="91"/>
<junction x="-137.16" y="76.2"/>
<pinref part="22" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="40.64" x2="-137.16" y2="40.64" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="40.64" x2="-137.16" y2="58.42" width="0.1524" layer="91"/>
<junction x="-137.16" y="58.42"/>
<pinref part="23" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="22.86" x2="-137.16" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="22.86" x2="-137.16" y2="40.64" width="0.1524" layer="91"/>
<junction x="-137.16" y="40.64"/>
<pinref part="24" gate="G$1" pin="VCC"/>
<wire x1="-99.06" y1="5.08" x2="-137.16" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="5.08" x2="-137.16" y2="22.86" width="0.1524" layer="91"/>
<junction x="-137.16" y="22.86"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="12" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="-5.08" x2="-20.32" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="-5.08" x2="-20.32" y2="12.7" width="0.1524" layer="91"/>
<pinref part="11" gate="G$1" pin="GND"/>
<wire x1="-20.32" y1="12.7" x2="-58.42" y2="12.7" width="0.1524" layer="91"/>
<pinref part="10" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="30.48" x2="-20.32" y2="30.48" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="30.48" x2="-20.32" y2="12.7" width="0.1524" layer="91"/>
<junction x="-20.32" y="12.7"/>
<pinref part="9" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="48.26" x2="-20.32" y2="48.26" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="48.26" x2="-20.32" y2="30.48" width="0.1524" layer="91"/>
<junction x="-20.32" y="30.48"/>
<pinref part="8" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="66.04" x2="-20.32" y2="66.04" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="66.04" x2="-20.32" y2="48.26" width="0.1524" layer="91"/>
<junction x="-20.32" y="48.26"/>
<pinref part="7" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="83.82" x2="-20.32" y2="83.82" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="83.82" x2="-20.32" y2="66.04" width="0.1524" layer="91"/>
<junction x="-20.32" y="66.04"/>
<pinref part="6" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="101.6" x2="-20.32" y2="101.6" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="101.6" x2="-20.32" y2="83.82" width="0.1524" layer="91"/>
<junction x="-20.32" y="83.82"/>
<pinref part="5" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="119.38" x2="-20.32" y2="119.38" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="119.38" x2="-20.32" y2="101.6" width="0.1524" layer="91"/>
<junction x="-20.32" y="101.6"/>
<pinref part="4" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="137.16" x2="-20.32" y2="137.16" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="137.16" x2="-20.32" y2="119.38" width="0.1524" layer="91"/>
<junction x="-20.32" y="119.38"/>
<pinref part="3" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="154.94" x2="-20.32" y2="154.94" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="154.94" x2="-20.32" y2="137.16" width="0.1524" layer="91"/>
<junction x="-20.32" y="137.16"/>
<pinref part="2" gate="G$1" pin="GND"/>
<wire x1="-58.42" y1="172.72" x2="-20.32" y2="172.72" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="172.72" x2="-20.32" y2="154.94" width="0.1524" layer="91"/>
<junction x="-20.32" y="154.94"/>
<pinref part="1" gate="G$1" pin="GND"/>
<pinref part="GND" gate="-1" pin="1"/>
<wire x1="-58.42" y1="190.5" x2="-20.32" y2="190.5" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="190.5" x2="-17.78" y2="190.5" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="172.72" x2="-20.32" y2="190.5" width="0.1524" layer="91"/>
<junction x="-20.32" y="172.72"/>
<junction x="-20.32" y="190.5"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="DIN" gate="-1" pin="1"/>
<pinref part="13" gate="G$1" pin="DATAS"/>
<wire x1="-121.92" y1="195.58" x2="-99.06" y2="195.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="1" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="195.58" x2="-45.72" y2="195.58" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="195.58" x2="-45.72" y2="177.8" width="0.1524" layer="91"/>
<pinref part="2" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="177.8" x2="-58.42" y2="177.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="14" gate="G$1" pin="DATAS"/>
<wire x1="-99.06" y1="177.8" x2="-111.76" y2="177.8" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="177.8" x2="-111.76" y2="160.02" width="0.1524" layer="91"/>
<pinref part="15" gate="G$1" pin="DATAS"/>
<wire x1="-111.76" y1="160.02" x2="-99.06" y2="160.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="3" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="160.02" x2="-45.72" y2="160.02" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="160.02" x2="-45.72" y2="142.24" width="0.1524" layer="91"/>
<pinref part="4" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="142.24" x2="-58.42" y2="142.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="16" gate="G$1" pin="DATAS"/>
<wire x1="-99.06" y1="142.24" x2="-111.76" y2="142.24" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="142.24" x2="-111.76" y2="124.46" width="0.1524" layer="91"/>
<pinref part="17" gate="G$1" pin="DATAS"/>
<wire x1="-111.76" y1="124.46" x2="-99.06" y2="124.46" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="5" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="124.46" x2="-45.72" y2="124.46" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="124.46" x2="-45.72" y2="106.68" width="0.1524" layer="91"/>
<pinref part="6" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="106.68" x2="-58.42" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="18" gate="G$1" pin="DATAS"/>
<wire x1="-99.06" y1="106.68" x2="-111.76" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="106.68" x2="-111.76" y2="88.9" width="0.1524" layer="91"/>
<pinref part="19" gate="G$1" pin="DATAS"/>
<wire x1="-111.76" y1="88.9" x2="-99.06" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="7" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="88.9" x2="-45.72" y2="88.9" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="88.9" x2="-45.72" y2="71.12" width="0.1524" layer="91"/>
<pinref part="8" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="71.12" x2="-58.42" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="20" gate="G$1" pin="DATAS"/>
<wire x1="-99.06" y1="71.12" x2="-111.76" y2="71.12" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="71.12" x2="-111.76" y2="53.34" width="0.1524" layer="91"/>
<pinref part="21" gate="G$1" pin="DATAS"/>
<wire x1="-111.76" y1="53.34" x2="-99.06" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="22" gate="G$1" pin="DATAS"/>
<wire x1="-99.06" y1="35.56" x2="-111.76" y2="35.56" width="0.1524" layer="91"/>
<wire x1="-111.76" y1="35.56" x2="-111.76" y2="17.78" width="0.1524" layer="91"/>
<pinref part="23" gate="G$1" pin="DATAS"/>
<wire x1="-111.76" y1="17.78" x2="-99.06" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="10" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="35.56" x2="-45.72" y2="35.56" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="35.56" x2="-45.72" y2="53.34" width="0.1524" layer="91"/>
<pinref part="9" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="53.34" x2="-58.42" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="11" gate="G$1" pin="DATAS"/>
<wire x1="-58.42" y1="17.78" x2="-45.72" y2="17.78" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="17.78" x2="-45.72" y2="0" width="0.1524" layer="91"/>
<pinref part="12" gate="G$1" pin="DATAS"/>
<wire x1="-45.72" y1="0" x2="-58.42" y2="0" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
