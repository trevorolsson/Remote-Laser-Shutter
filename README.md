# Basic Remote Laser Shutter
<html>
<p>
  This is a very basic proof-of-concept for a remote-controlled shutter. I created this out of frustration with the companies that sell a similar product for hundreds to thousands of dollars. While the functionality of this code is limited to a infrared-signal remote, my hope is that some undergraduate or graduate student can take what I have developed and make it better for their own use.
  </p>
  <hr></hr>
  <b>To use the code</b>
  <p>You must have an editor for C++ code, and a way to upload this code into a specific Arduino board. For this project, I have used an <a href="https://store-usa.arduino.cc/products/arduino-nano/">ArduinoNANO-like</a> board, as its compact design has allowed me to minimize the size of the shutter I put into the laser beamline, making it similar in size to other optical elements. The editor I have chosen is the native IDE for arduino found at <a href="https://www.arduino.cc/en/software">https://www.arduino.cc/en/software</a> .</p>
  <ul>
  <li>Download </li>
  <ol>
    <li><code>serial_hex_decode.ino</code> is a program written by Ken Shirrif at <a href="http://dronebotworkshop.com">DroneBot Workshop</a> that allows you to read the signal being received by the infrared signal detector. This signal is printed as hexadecimal code, and varies depending on the button you push on the remote. For my code, you will need to choose two buttons to act as <i>on</i> and <i>off</i> by copying and pasting the respective hexadecimal codes into my program.</li>
  <li> <code>IR_select_main_v2b.ino</code> is the program you will upload to your Arduino board. This is what sends the signal to the servo motor as a toggle to move the arm.</li>
  </ol>
  </ul> 
  <hr></hr>
  <b>The construction of the holder</b>
  <p>The only essential parts for this shutter are the servo motor, Arduino board, detector and code, but if you wanted to construct the housing for these components, I have included these in the relevent files.</p>
  <ul>
  <li>The housing for the shutter was made in Solidworks and was intended to be 3D printed, but it can also be machined out of aluminum if you have that capability. The idea was to make it cheap, and east to put together.</li>
  <li>The flag and face plate was intended to be machined out of aluminum, as a laser with sufficient intensity could melt plastic.</li>
  <li>The screws used are indicated in the Solidworks schematics.</li>
  </ul>
  <hr></hr>
  <b>Known Issues</b>
  <ul>
  <li>It may just be for the remote I'm using, but if the shutter isn't used for a long time, when it is powered on and made to read the remote signal, the hex code will be different even if the same buttons are being used. </li>
  <li>If there is a lot of background signal (bright lights or large diffuse scattering from laser etc), the receiver will not see the remote.</li>
  <li>This read-me was hastily thrown together. I will fix this later :)</li>
</ul>
</html>
