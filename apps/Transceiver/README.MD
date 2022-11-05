=== Build steps: ===

cd into telemetry/apps/Transceiver
leaf shell //OR have the framework configured for WP76xx target
mkapp -t wp76xx transceiver.adef


=== Install onto hardware: ===

update transceiver.wp76xx.update 192.168.2.2


=== View on hardware: ===

have two terminals connected to root@192.168.2.2

on first terminal run:
logread -f | grep "<expected printout>"

on second terminal run:
app stop transceiver
app start transceiver 
app info transceiver 

=== Documentation ===

Documentationi located at [mangOH Red Getting Started Guide (Linux) [Rev5]](http://mangoh.io/uploaded-documents/Reference/mangOH%20Red/Discover/Getting%20Started/mangOH%20Red%20GSG%20-%20Linux%20R5/#t=41112261_mangOH_Red_GSG_-_HTML5%2F41112261_Tut_Quick_Start%2F41112261_Tut_Quick_Start.htm)

=== Debugging === 

Check the status of the antenna:
cm radio
Check the status of the connection:
cm data

While plugged into the car, to check the status of can:
ifconfig can0

To manually start the can driver:
Be in root folder of mangoh
sh start_can.sh red

To manually connect to data:
cm data connect

To change the apn to that of your carrier:
cm data apn <apn_value>

logread -f | grep "transceiver"