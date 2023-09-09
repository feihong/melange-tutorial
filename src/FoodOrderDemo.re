[@react.component]
let make = () =>
  <>
    <FoodOrder
      order=[|
        Hotdog,
        Sandwich(Ham),
        Burger({lettuce: true, tomatoes: true, bacon: 3, onions: 1, cheese: 2}),
        Sandwich(Unicorn),
      |]
    />
  </>;
