/* [Global] */
//Diametre du bouton
Knob_Diameter=13; //[10:30]
//Hauteur du bouton
Knob_Height=15;//[10:20]
//Longueur de l'axe
Axis_Length=10;//[5:15]
//Arrondis
Rounded=2;//[1:3]
//Ajustement
Adjustment=0.3;//[0,0.1,0.2,0.3]
/* [Hidden] */
$fn=50;

difference() {
  union() {
      cylinder(r=Knob_Diameter/2,h=Knob_Height-Rounded);
      translate([0,0,Knob_Height-Rounded]) cylinder(r=Knob_Diameter/2-Rounded,h=Rounded);
      translate([0,0,Knob_Height-Rounded]) rotate_extrude(convexity = 10) translate([Knob_Diameter/2-Rounded,0,0])  circle(r=Rounded);
  }
  
  //translate([0,0,Knob_Height]) rotate([-90,0,0]) cylinder(r=0.5,h=Knob_Diameter/2);
  //translate([0,0,Knob_Height]) sphere(r=0.5);
  
  for (i=[22.5:45:360]) translate([(Knob_Diameter+0.6)*sin(i)/2,(Knob_Diameter+0.6)*cos(i)/2,3]) cylinder(r=0.7,h=Knob_Height);
  difference() {
      translate([0,0,2]) cylinder(r=3.1+Adjustment,h=Axis_Length-2);
      translate([-5,-6.6-Adjustment,2]) cube([10,5,Axis_Length-2]);
  }
  difference() {
      cylinder(r=3+Adjustment,h=2);
      translate([-5,-6.5-Adjustment,0]) cube([10,5,Axis_Length-2]);
  }
}
