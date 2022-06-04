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
