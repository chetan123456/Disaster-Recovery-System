var map;
var sensorNum;
var gif;
var checkStatement=true;//just check the boolean
var checkStatement1=true;


var tempratureVariable;

var y = 100;
var serial; // variable to hold an instance of the serial port library

function setup() {
//checkStatement = true;
  createCanvas(200, 700);
  //gif = load("animated-fire.gif");
  //frameRate(30);
  serial = new p5.SerialPort();  // make a new instance of  serialport library
//  serial.on('list', printList);  // callback function for serialport list event

  serial.on('data', serialEvent);// callback for new data coming in
	serial.list();                         // list the serial ports
	serial.open("/dev/cu.usbmodemfa131"); // open a port

}

function draw() {



  //background(0);   // Set the background to black
  // fill(0,0,0,1);
  // rect(10, 50, width, height/2 - 70);
  // print("test");

  // fill(255, 255, 255);
  // text("Sensor Info", 10, 90);
  // strokeWeight(0);
  // textFont("Helvetica");
  // textStyle(NORMAL);
  // textSize(20);


  //----------------------
}

function initMap() {
  map = new google.maps.Map(document.getElementById('map'), {
    center: {lat: 40.729446, lng: -73.993907},
    zoom: 20,
    mapTypeId: 'satellite',
    heading: 90,
    tilt: 40
  });
}

function rotate90() {
  var heading = map.getHeading() || 0;
  map.setHeading(heading + 90);
}

function autoRotate() {
  // Determine if we're showing aerial imagery.
  if (map.getTilt() !== 30) {
    window.setInterval(rotate10, 300);
  }
}

function serialEvent() {
	var inString = serial.readLine(); // '300'
  console.log(inString);
	if (inString.length > 0) {
	  inString = inString.trim();
    // takes "934" and turns it into 934
		//sensorValue = Number(inString);

    //int sensors[] = int(split(inString, ','));
    var sensors = inString.split(','); // ['300']

    for (var i = 0; i < sensors.length; i++) {
      sensors[i] = Number(sensors[i]);
    }

    // [300]

    console.log("Hello");
    for (sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      console.log("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t");
      tempratureVariable = sensors[0];
      print("temprature variable value "+tempratureVariable);
      tempratureVariablePot1 = sensors[1];
      print("temprature variable value1 "+tempratureVariablePot1);

}


if (tempratureVariable > 30){
  checkStatement = false;
  var intervalID = window.setInterval(myCallBack, 1000);
}

if (tempratureVariable < 30){
  checkStatement = true;
  var intervalID2 = window.setInterval(myCallBack, 1000);
}

if (tempratureVariablePot1 > 300){
  checkStatement1 = false;
  var intervalID3 = window.setInterval(myCallBack1, 1000);
}

if (tempratureVariablePot1 < 300){
  checkStatement1 = true;
  var intervalID4 = window.setInterval(myCallBack1, 1000);  
}

//Try1--------
    // if(sensorValue !== 0){
    //   fill(255, 255, 255);
    //   noStroke();
    //   textSize(24);
    //   textStyle(NORMAL);
    //   textFont("Helvetica");
    //   text("ITP: Fire 4th floor", 60, 200, 100, 120);
    //   text ()
    //
    // }
    //
    // if(sensorValue == 0){
    //   fill(255, 255, 255);
    //   noStroke();
    //   textSize(24);
    //   textStyle(NORMAL);
    //   textFont("Helvetica");
    //   text("ITP: Waiting", 140, 300, 100, 120);
    //
    // }

  //  println("sensorValue"+sensorValue);
  //  println("rectValue"+rectValue);
	}


}
