let initFahrenheit = {js|? °F|js};

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => initFahrenheit);

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newValue = ReactEvent.Form.target(evt)##value |> String.trim;
        setCelsius(_ => newValue);
        switch (float_of_string(newValue)) {
        | exception _ => setFahrenheit(_ => newValue == "" ? initFahrenheit : "error")
        | celsius =>
          let fahrenheit = 9.0 /. 5.0 *. celsius +. 32.0;
          setFahrenheit(_ => string_of_float(fahrenheit) ++ {js| °F|js});
        };
      }}
    />
    {React.string({js|°C = |js})}
    <span> {React.string(fahrenheit)} </span>
  </div>;
};
