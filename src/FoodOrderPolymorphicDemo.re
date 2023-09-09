module LunchOrder = FoodOrderPolymorphic.LunchOrder;
module DinnerOrder = FoodOrderPolymorphic.DinnerOrder;

[@react.component]
let make = () =>
  <>
    <Subtitle label="LunchOrder" />
    <LunchOrder
      order=[|
        `Hotdog,
        `Meatpie,
        `Sandwich(Ham),
        `Burger({lettuce: false, tomatoes: false, bacon: 0, onions: 0, cheese: 6}),
        `Sandwich(Unicorn),
      |]
    />
    <Subtitle label="DinnerOrder" />
    <DinnerOrder
      order=[|
        `Steak,
        `Ramen,
        `Sandwich(Portabello),
        `Burger({lettuce: true, tomatoes: true, bacon: 1, onions: 0, cheese: 0}),
        `Sandwich(Unicorn),
      |]
    />
  </>;
