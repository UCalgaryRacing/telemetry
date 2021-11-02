#
# AUTO-GENERATED Makefile; do not edit, changes will be lost
#

# Define target type
TARGET:=wp750x

# Custom makefile include: initialization
-include ../customInit.mk

# Only when not cleaning
ifneq ($(MAKECMDGOALS),clean)
endif

# Target artifact.*
TARGET_ARTIFACT:=red.$(TARGET).update

# Clean command
CLEANCOMMAND:=find -maxdepth 1 -mindepth 1 ! -name Makefile ! -name .rsync-rules -exec rm -R {} \;

# MK command
MKCOMMAND:=cd ..;mksys $(MKSYS_FLAGS) -t $(TARGET) -o Target_Legato_Debug -w Target_Legato_Debug --cflags=-O2 --object-dir=build/$@ --output-dir=$(UPDATE_FILE_DIR) -i "$(LEGATO_ROOT)/interfaces/positioning" -i "$(LEGATO_ROOT)/interfaces/secureStorage" -i "$(LEGATO_ROOT)/interfaces/modemServices" -i "$(LEGATO_ROOT)/interfaces/wifi" -i "$(LEGATO_ROOT)/interfaces/airVantage" -i "$(LEGATO_ROOT)/interfaces/watchdog" -i "$(LEGATO_ROOT)/interfaces/atServices" -i "$(LEGATO_ROOT)/interfaces/logDaemon" -i "$(LEGATO_ROOT)/interfaces" -i "$(LEGATO_ROOT)/interfaces/supervisor" -i "$(LEGATO_ROOT)/interfaces/portService" -i "$(LEGATO_ROOT)/interfaces/airVantage/legacy" -s "$(LEGATO_ROOT)/apps/platformServices/airVantageConnector" -s "samples/tutorials/mangOH_Red/i2c/BatteryChargerReading" -s "samples/tutorials/mangOH_Red/gpio/TouchSensor" -s "samples/BsecTest" -s "samples/RelayControl" -s "apps/locationService" -s "$(LEGATO_ROOT)/components/airVantage" -s "samples/tutorials/mangOH_Green/adc/NoiseSensor" -s "$(LEGATO_ROOT)/apps/platformServices/airVantage" -s "apps/BatteryService" -s "samples/tutorials/developerDay2016/components" -s "apps/GpioExpander/gpioExpanderService" -s "apps/OpenWeatherMapAmbientTemperature" -s "$(LEGATO_ROOT)/components/portService" -s "$(LEGATO_ROOT)/components/modemServices/platformAdaptor/default" -s "apps/DataHub/test" -s "apps/Heartbeat" -s "apps/ntag" -s "apps/RedSensorToCloud/components" -s "apps/DataHub-Buzzer" -s "samples/BluetoothSensorTag" -s "$(LEGATO_ROOT)/components/audio/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/3rdParty" -s "samples/tutorials/voice" -s "$(LEGATO_ROOT)/components/fwupdate/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/dataConnectionService" -s "$(LEGATO_ROOT)/components/airVantage/platformAdaptor/default" -s "samples/tutorials/mangOH_Green/i2c/BatteryChargerReading" -s "$(LEGATO_ROOT)/components/positioning/platformAdaptor/default" -s "$(LEGATO_ROOT)/apps/proprietary/atAirVantage/bin/wp85" -s "$(LEGATO_ROOT)/components/devMode" -s "samples/IioDeviceList" -s "$(LEGATO_ROOT)/apps/proprietary/qmiAirVantage/bin/wp85" -s "$(LEGATO_ROOT)/components/modemServices" -s "apps/YellowSensor/components/sensors" -s "apps/DataHub/components" -s "apps/Bme680EnvironmentalSensor" -s "apps/ArduinoBridge" -s "apps/RedSensorToCloud/components/sensors" -s "samples/Demos/LegatoWebsocketd" -s "samples/Demos/KillSwitch" -s "apps/Welcome/components" -s "apps/MqttClient" -s "apps/Telemetry" -s "apps/test/YellowEnvironment" -s "$(LEGATO_ROOT)/components/dataConnectionService/platformAdaptor/default" -s "$(LEGATO_ROOT)/modules/WiFi/apps/tools/wifi" -s "samples/Demos/MobileAssetTracker" -s "apps/YellowSensor/components" -s "$(LEGATO_ROOT)/components/positioning" -s "$(LEGATO_ROOT)/components/secStore" -s "$(LEGATO_ROOT)/components/uartMode/platformAdaptor/default" -s "samples/tutorials/mangOH_Red/AirVantage/ButtonToAirVantage" -s "samples/Demos/WiredSensor" -s "apps/SocialService" -s "samples/tutorials/mangOH_Green/gpio/Cf3GpioControl" -s "apps/BluetoothServices" -s "samples/tutorials/mangOH_Red/gpio/TimerLed" -s "apps/MuxControl/tools" -s "$(LEGATO_ROOT)/apps/tools" -s "apps/YellowOnBoardActuators/components" -s "samples/BatteryClient" -s "samples/Demos/GpsPublish" -s "$(LEGATO_ROOT)/apps/proprietary/atQmiLinker/bin/wp85" -s "apps/DataRouter" -s "apps/NtagDhubIf" -s "$(LEGATO_ROOT)/modules/WiFi/service" -s "samples/Demos/CheckState" -s "samples/tutorials/mangOH_Green/gpio/TouchSensor" -s "samples/tutorials/mangOH_Red/adc/NoiseSensor" -s "$(LEGATO_ROOT)/components/fwupdate" -s "apps/MuxControl/muxCtrlService" -s "samples/Demos/ShakeNWake" -s "apps/LedService" -s "$(LEGATO_ROOT)/components/secStore/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/atServices" -s "apps/GpioExpander/gpioExpanderDemo" -s "$(LEGATO_ROOT)/components/uartMode" -s "$(LEGATO_ROOT)/components" -s "samples/tutorials/mangOH_Red/gpio/Cf3GpioControl" -s "components" -s "$(LEGATO_ROOT)/apps/platformServices" -s "apps/VegasMode" -s "apps/DataRouter/drTool" -s "samples/tutorials/mangOH_Green/gpio/TimerLed" -C -g -X -g -L -g red.sdef

# Custom makefile include: definitions
-include ../customDefs.mk

.PHONY: all target clean codegen mkCodegen systocwe

all: target systocwe

codegen: mkCodegen

mkCodegen:
	$(MKCOMMAND) --generate-code

target:
	$(MKCOMMAND)

systocwe:
	systocwe $(TARGET) $(TARGET_ARTIFACT) cwe


clean:
	$(CLEANCOMMAND)


# Custom makefile include: targets
-include ../customTargets.mk
