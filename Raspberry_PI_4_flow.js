[{"id":"a400a6e7.e01ea8","type":"tab","label":"Flow 1","disabled":false,"info":""},{"id":"94a581c4.52f3b","type":"camerapi-takephoto","z":"a400a6e7.e01ea8","filemode":"1","filename":"photo1.jpeg","filedefpath":"0","filepath":"/home/pi/Pictures/","fileformat":"jpeg","resolution":"10","rotation":"180","fliph":"0","flipv":"0","brightness":"50","contrast":"0","sharpness":"0","quality":"80","imageeffect":"none","exposuremode":"auto","iso":"0","agcwait":"1.0","led":"0","awb":"auto","name":"","x":640,"y":400,"wires":[[]]},{"id":"485521ae.5303","type":"mqtt out","z":"a400a6e7.e01ea8","name":"","topic":"Image","qos":"","retain":"","broker":"8fd9614d.29c4f","x":630,"y":340,"wires":[]},{"id":"17d08f88.c9673","type":"delay","z":"a400a6e7.e01ea8","name":"","pauseType":"rate","timeout":"5","timeoutUnits":"seconds","rate":"1","nbRateUnits":"10","rateUnits":"second","randomFirst":"1","randomLast":"5","randomUnits":"seconds","drop":true,"x":400,"y":400,"wires":[["94a581c4.52f3b","485521ae.5303"]]},{"id":"2844ae16.920102","type":"mqtt in","z":"a400a6e7.e01ea8","name":"","topic":"parking/entrance","qos":"2","datatype":"auto","broker":"f3ec7454.63e1f8","x":180,"y":400,"wires":[["17d08f88.c9673"]]},{"id":"69a5f329.b8f5ec","type":"mqtt in","z":"a400a6e7.e01ea8","name":"","topic":"parking/slot1","qos":"2","datatype":"auto","broker":"f3ec7454.63e1f8","x":210,"y":560,"wires":[["9e1af9c1.f33e88"]]},{"id":"9e1af9c1.f33e88","type":"mqtt out","z":"a400a6e7.e01ea8","name":"","topic":"Slot1_status","qos":"","retain":"","broker":"8fd9614d.29c4f","x":430,"y":560,"wires":[]},{"id":"8fd9614d.29c4f","type":"mqtt-broker","name":"PC","broker":"127.0.0.1","port":"1883","clientid":"","usetls":false,"compatmode":false,"keepalive":"60","cleansession":true,"birthTopic":"","birthQos":"0","birthPayload":"","closeTopic":"","closeQos":"0","closePayload":"","willTopic":"","willQos":"0","willPayload":""},{"id":"f3ec7454.63e1f8","type":"mqtt-broker","name":"Wemos","broker":"localhost","port":"1883","clientid":"","usetls":false,"compatmode":false,"keepalive":"60","cleansession":true,"birthTopic":"","birthQos":"0","birthPayload":"","closeTopic":"","closeQos":"0","closePayload":"","willTopic":"","willQos":"0","willPayload":""}]
